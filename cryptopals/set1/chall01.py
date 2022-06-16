#!/usr/bin/env python3

"""
converts hex to base64
"""

import base64

def hex_base64(string):
    b64 = base64.b64encode(bytes.fromhex(string)).decode()
    return b64

hex = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d"
print(hex_base64(hex))
