#!/usr/bin/env python3
"""
Takes a hex encoded string that has been XOR'd against a single character.
Finds the key, and decrypt's the message
"""
import pwn
from collections import Counter
from string import ascii_lowecase, ascii_uppercase, ascii_letters

def mySolution:
    """
    for my solution I did a for loop, then scrolled to check for a string
    then went ahead and placed an if statement to print my deciphered text
    """
    string = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736"
    cipher = pwn.unhex(string)

    for i in range(256):
        message = pwn.xor(cipher, i)
        if (b'Cooking' in message):
            print(i, message)
            exit()

def ExpectedSolution:
    """
    using frequency analysis
    """
