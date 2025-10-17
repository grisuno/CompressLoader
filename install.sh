#!/bin/bash
sudo apt update
sudo apt install mingw-w64

x86_64-w64-mingw32-gcc loader.c -o loader.exe -lwinhttp -lcrypt32 -lpsapi -static -s -O2 && cp loader.exe /home/grisun0/LazyOwn/sessions
x86_64-w64-mingw32-gcc loader3.c -o loader2.exe -lwinhttp -lcrypt32 -lpsapi -static -s -O2 && cp loader2.exe /home/grisun0/LazyOwn/sessions
x86_64-w64-mingw32-gcc loader3.c -o loader3.exe -lwinhttp -lcrypt32 -lpsapi -static -s -O2 && cp loader3.exe /home/grisun0/LazyOwn/sessions
x86_64-w64-mingw32-gcc loader4.c -o loader4.exe -lwinhttp -lcrypt32 -lpsapi -static -s -O2 && cp loader4.exe /home/grisun0/LazyOwn/sessions

