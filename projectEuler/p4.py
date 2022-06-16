#!/usr/bin/env python3
"""
problem 4; Largest palindrome product
"""

max = 0

for a in range(100, 1000):
    for b in range(100, 1000):
        prod = a * b
        temp = prod
        rev = 0

        while temp != 0:
            rev = (rev * 10) + (temp % 10)
            temp //= 10
        if (rev == prod):
            if (prod > max):
                max = prod
                x = a
                y = b

print(f"The largest palindrome made from the product of two 3-digit numbers is {max} = {x} * {y}\n")
