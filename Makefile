# CompressLoader Makefile
# ========================

CC       := gcc
MINGW    := x86_64-w64-mingw32-gcc
CFLAGS   := -O2 -s
LDFLAGS  := -lm
WINFLAGS := -lwinhttp -lcrypt32 -lpsapi -static
STRIP    := strip

INSTALL_DIR ?= /home/grisun0/LazyOwn/sessions
PAYLOAD_DIR := payloads
PE_FILE     ?= /dev/null  # override: make payload PE_FILE=mimikatz.exe

SERVER_HOST ?= 0.0.0.0
SERVER_PORT ?= 8080

TEST_FILE  := /tmp/cl_test_data.bin
TEST_LZSS  := /tmp/cl_test.lzss
TEST_OUT   := /tmp/cl_test_out.bin
TEST_SIZE  ?= 1048576  # 1MB

# Colors
BOLD    := \033[1m
GREEN   := \033[32m
YELLOW  := \033[33m
RED     := \033[31m
CYAN    := \033[36m
RESET   := \033[0m

.PHONY: all pack-tools loaders config test payload install uninstall clean distclean run serve info help

# ── Default ────────────────────────────────────────────
all: pack-tools loaders

# ── Information ────────────────────────────────────────
info:
	@echo "$(BOLD)$(CYAN)CompressLoader$(RESET)"
	@echo "  CC:           $(CC)"
	@echo "  MINGW:        $(MINGW)"
	@echo "  INSTALL_DIR:  $(INSTALL_DIR)"
	@echo "  SERVER:       $(SERVER_HOST):$(SERVER_PORT)"
	@echo ""
	@echo "$(BOLD)Targets:$(RESET)"
	@echo "  all        Build everything (pack-tools + loaders)"
	@echo "  pack-tools Build LZSS pack/unpack (Linux native)"
	@echo "  loaders    Cross-compile loader*.exe (Windows)"
	@echo "  config     Install build dependencies"
	@echo "  test       Full LZSS roundtrip test"
	@echo "  payload    Build encrypted payload (PE_FILE=...)"
	@echo "  install    Build + install to INSTALL_DIR"
	@echo "  uninstall  Remove installed loaders"
	@echo "  run        Serve payloads over HTTP"
	@echo "  clean      Remove build artifacts"
	@echo "  distclean  Clean everything (payloads too)"

help: info

# ── Configuration ──────────────────────────────────────
config:
	@echo "$(YELLOW)[*] Checking dependencies...$(RESET)"
	@which $(CC)       >/dev/null 2>&1 || (echo "$(RED)[-] gcc not found — install build-essential$(RESET)" && exit 1)
	@which $(MINGW)    >/dev/null 2>&1 || (echo "$(YELLOW)[!] mingw-w64 not found — run: sudo apt install mingw-w64$(RESET)")
	@which python3     >/dev/null 2>&1 || (echo "$(RED)[-] python3 not found$(RESET)" && exit 1)
	@python3 -c 'import Crypto' >/dev/null 2>&1 || (echo "$(YELLOW)[!] pycryptodome missing — run: pip install -r requirements.txt$(RESET)")
	@echo "$(GREEN)[+] Dependencies checked$(RESET)"

# ── LZSS tools (Linux native) ──────────────────────────
pack-tools: pack unpack lzss-test

pack: lzss.c pack.c
	@echo "$(YELLOW)[*] Building pack...$(RESET)"
	$(CC) $(CFLAGS) lzss.c pack.c -o pack $(LDFLAGS)
	@echo "$(GREEN)[+] pack built$(RESET)"

unpack: lzss.c unpack.c
	@echo "$(YELLOW)[*] Building unpack...$(RESET)"
	$(CC) $(CFLAGS) lzss.c unpack.c -o unpack $(LDFLAGS)
	@echo "$(GREEN)[+] unpack built$(RESET)"

lzss-test: lzss.c test.c
	@echo "$(YELLOW)[*] Building lzss-test...$(RESET)"
	$(CC) $(CFLAGS) lzss.c test.c -o lzss-test $(LDFLAGS)
	@echo "$(GREEN)[+] lzss-test built$(RESET)"

# ── Loaders (Windows cross-compile) ────────────────────
LOADER_SRCS := loader.c loader2.c loader3.c loader4.c
LOADER_EXES := $(LOADER_SRCS:.c=.exe)

loaders: $(LOADER_EXES)

%.exe: %.c
	@echo "$(YELLOW)[*] Cross-compiling $< -> $@$(RESET)"
	$(MINGW) $(CFLAGS) $< -o $@ $(WINFLAGS) 2>&1 || (echo "$(RED)[-] Cross-compile failed — is mingw-w64 installed?$(RESET)" && exit 1)
	@echo "$(GREEN)[+] $@ built ($$(stat -c%s $@) bytes)$(RESET)"

# ── Full cycle test ────────────────────────────────────
test: pack-tools
	@echo ""
	@echo "$(BOLD)$(CYAN)═══ LZSS Roundtrip Test ═══$(RESET)"
	@SZ=$$(echo $(TEST_SIZE) | numfmt --from=auto 2>/dev/null || echo $(TEST_SIZE)); \
	echo "$(YELLOW)[*] Generating $$SZ bytes of random data...$(RESET)"; \
	dd if=/dev/urandom of=$(TEST_FILE) bs=$$SZ count=1 status=none 2>/dev/null; \
	orig_sz=$$(stat -c%s $(TEST_FILE)); \
	echo "$(GREEN)[+] Generated $(TEST_FILE) ($$orig_sz bytes)$(RESET)"; \
	echo "$(YELLOW)[*] Compressing...$(RESET)"; \
	./pack $(TEST_FILE) $(TEST_LZSS); \
	lzss_sz=$$(stat -c%s $(TEST_LZSS)); \
	pct=$$(awk "BEGIN {printf \"%.1f\", $$lzss_sz * 100.0 / $$orig_sz}"); \
	echo "$(GREEN)[+] Compressed: $$orig_sz -> $$lzss_sz bytes ($$pct%)$(RESET)"; \
	echo "$(YELLOW)[*] Decompressing...$(RESET)"; \
	./unpack $(TEST_LZSS) $(TEST_OUT) >/dev/null; \
	out_sz=$$(stat -c%s $(TEST_OUT)); \
	echo "$(GREEN)[+] Decompressed: $$out_sz bytes$(RESET)"; \
	echo "$(YELLOW)[*] Verifying...$(RESET)"; \
	if cmp -s $(TEST_FILE) $(TEST_OUT); then \
		echo "$(GREEN)[+] PASS: roundtrip OK ($$orig_sz bytes identical)$(RESET)"; \
		rm -f $(TEST_FILE) $(TEST_LZSS) $(TEST_OUT); \
	else \
		echo "$(RED)[-] FAIL: files differ!$(RESET)"; \
		exit 1; \
	fi

# ── Payload generation ─────────────────────────────────
payload: pack-tools
	@echo ""
	@echo "$(BOLD)$(CYAN)═══ Payload Builder ═══$(RESET)"
	@if [ ! -f "$(PE_FILE)" ]; then \
		echo "$(RED)[-] PE file not found: $(PE_FILE)$(RESET)"; \
		echo "  Usage: make payload PE_FILE=/path/to/target.exe"; \
		exit 1; \
	fi
	@echo "$(YELLOW)[*] PE file: $(PE_FILE) ($$(stat -c%s $(PE_FILE) 2>/dev/null || echo '?') bytes)$(RESET)"
	@mkdir -p $(PAYLOAD_DIR)
	@echo "$(YELLOW)[*] Building payload with crypter.py...$(RESET)"
	@python3 crypter.py "$(PE_FILE)" 2>&1 | sed 's/^/  /'
	@if [ -f payload.bin ]; then \
		mv payload.bin $(PAYLOAD_DIR)/; \
		echo "$(GREEN)[+] Payload saved: $(PAYLOAD_DIR)/payload.bin ($$(stat -c%s $(PAYLOAD_DIR)/payload.bin) bytes)$(RESET)"; \
	fi

# ── Install / Uninstall ────────────────────────────────
install: loaders
	@echo "$(YELLOW)[*] Installing to $(INSTALL_DIR)...$(RESET)"
	@mkdir -p $(INSTALL_DIR)
	@for exe in $(LOADER_EXES); do \
		if [ -f "$$exe" ]; then \
			cp -v "$$exe" $(INSTALL_DIR)/; \
		fi; \
	done
	@echo "$(GREEN)[+] Installed $(words $(LOADER_EXES)) loaders to $(INSTALL_DIR)$(RESET)"

uninstall:
	@echo "$(YELLOW)[*] Removing loaders from $(INSTALL_DIR)...$(RESET)"
	@for exe in $(LOADER_EXES); do \
		rm -fv "$(INSTALL_DIR)/$$exe"; \
	done
	@echo "$(GREEN)[+] Uninstalled$(RESET)"

# ── Serve payloads ─────────────────────────────────────
run: serve
serve:
	@if [ ! -d $(PAYLOAD_DIR) ]; then \
		mkdir -p $(PAYLOAD_DIR); \
		echo "$(YELLOW)[!] $(PAYLOAD_DIR)/ is empty — run: make payload PE_FILE=...$(RESET)"; \
	fi
	@echo "$(GREEN)[+] Serving $(PAYLOAD_DIR)/ on http://$(SERVER_HOST):$(SERVER_PORT) $(RESET)"
	@echo "    URL: http://$(SERVER_HOST):$(SERVER_PORT)/payload.bin"
	@echo "    Press Ctrl+C to stop"
	@cd $(PAYLOAD_DIR) && python3 -m http.server $(SERVER_PORT) --bind $(SERVER_HOST)

# ── Clean ──────────────────────────────────────────────
clean:
	@echo "$(YELLOW)[*] Cleaning build artifacts...$(RESET)"
	@rm -fv pack unpack lzss-test $(LOADER_EXES) *.o *.lzss
	@rm -f $(TEST_FILE) $(TEST_LZSS) $(TEST_OUT)
	@echo "$(GREEN)[+] Clean$(RESET)"

distclean: clean
	@echo "$(YELLOW)[*] Deep cleaning...$(RESET)"
	@rm -rfv $(PAYLOAD_DIR)
	@echo "$(GREEN)[+] Distclean$(RESET)"
