#!/usr/bin/env python3

"""
a function that takes two equal-length buffers
and produces their XOR combination
"""

def fixedXOR(buf1, buf2):
    # convert strings to binary
    bin1 = bin(int(buf1, 16))[2:]
    bin2 = bin(int(buf2, 16))[2:]

    # find a constant length
    length = len(bin1) if len(bin1) > len(bin2) else len(bin2)

    #make equal length
    bin1 = bin1.zfill(length)
    bin2 = bin2.zfill(length)

    xored = [int(bit1) ^ int(bit2) for bit1, bit2 in zip(bin1, bin2)]
    result = hex(int(''.join([str(bits) for bits in xored]), 2))[2:]
    return result

str1 = "1c0111001f010100061a024b53535009181c"
str2 = "686974207468652062756c6c277320657965"

print(fixedXOR(str1, str2))
