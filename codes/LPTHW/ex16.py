#!/usr/bin/env python3
"""
Reading and Writing Files ex16
"""

from sys import argv

if len(argv) != 2:
    print("Usage: ex16.py filename")
    exit()

script, filename = argv

print(f"We're going to erase {filename}.")
print("If you don't want that, hit CTRL-C (^C).")
print("If you do want that, hit RETURN.")

input("?")

print("Opening the file...")
target = open(filename, 'w')

#when opening with write mode, we don't really need to truncate it.
#print("Truncating the file. Goodbye!")
#target.truncate()

print("Now I'm going to ask you for three lines.")

line1 = input("line1: ")
line2 = input("line2: ")
line3 = input("line3: ")

print("I'm going to write these to the file.")

target.write(line1)
target.write("\n")
target.write(line2)
target.write("\n")
target.write(line3)
target.write("\n")

print("And finally, we close it")
target.close()

text = open(filename)

print(f"""
We are now going to print the new contents of {filename} filename
""")
print(text.read())
text.close()
