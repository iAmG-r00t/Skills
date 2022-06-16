#!/usr/bin/env python3
"""
Reading Files ex15

python3 -m pydoc open
"""

from sys import argv

if len(argv) != 2:
    print("Usage: ex15.py filename")
    exit()

script, filename = argv

text = open(filename)

print(f"Here's your file {filename}")
print(text.read())

text.close()

print("Type the filename again:")
file_again = input("> ")

text_again = open(file_again)

print(text_again.read())
text_again.close()
