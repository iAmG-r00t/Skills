#!/usr/bin/env python3
"""
Problem 6: Sum square difference
"""

sUm = 0
sqSum = 0

for num in range(1,101):
    sqSum += num ** 2
    sUm += num

print(f"The square of the sum is {(sUm * sUm)} and the sum of the squares is {sqSum}")
print(f"The difference is {(sUm * sUm) - sqSum}")
