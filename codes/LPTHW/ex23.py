#!/usr/bin/env python3
"""
Strings, Bytes, and Character Encodings ex23

encoding types: utf-8, utf-16, big5
error type: strict; that will allow us to handle
    the encode and decode unicode errors
"""

import sys

if len(sys.argv) != 3:
    print("Usage: ex23.py encoding-type error-type")
    exit()

script, encoding, error = sys.argv

def main(language_file, encoding, errors):
    line = language_file.readline()

    if line:
        print_line(line, encoding, errors)
        return main(language_file, encoding, errors)

def print_line(line, encoding, errors):
    next_lang = line.strip()
    raw_bytes = next_lang.encode(encoding, errors=errors)
    cooked_string = raw_bytes.decode(encoding, errors=errors)

    print(raw_bytes, "<===>", cooked_string)

languages = open("languages.txt", encoding="utf-8")

main(languages, encoding, error)
