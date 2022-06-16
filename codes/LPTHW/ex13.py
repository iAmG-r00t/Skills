#!/usr/bin/env python3
"""
Parameters, Unpacking, Variables ex13
"""

from sys import argv
# read the WYSS section for how to run this

# avoid error when feeded less arguments
if len(argv) != 4:
    print("Usage: ex13.py arg1 arg2 arg3")
    exit()

script, first, second, third = argv

ans = input("Would you love to see your results? ")

print(f"You answered: {ans}")
print("The script is called:", script)
print("Your first variable is:", first)
print("Your second variable is:", second)
print("Your third variable is:", third)
