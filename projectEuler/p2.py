#!/usr/bin/env python3
"""
Problem 2: Even Fibonacci Numbers
"""

fib1 = fib2 = nextTerm = 1
sum = 0

print(f"Fibonacci Sequence: {fib1}", end=", ")

while nextTerm < 4000000:
    nextTerm = fib1 + fib2;
    if (nextTerm > 4000000):
        print(f"{nextTerm}")
    else:
        print(f"{nextTerm}", end=", ")

    if nextTerm % 2 == 0:
        sum += nextTerm

    fib1 = fib2
    fib2 = nextTerm

print("Sum of even-valued is {}".format(sum))
