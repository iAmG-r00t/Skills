#!/usr/bin/env python3
"""
problem 3; Largest prime number
"""

from math import sqrt

def is_prime(num):
    for i in range(2, int(sqrt(num))):
        if num % i == 0:
            return False
    return True

def prime_factors(num):
    prime_factors = []
    
    for i in range(2, int(sqrt(num))):
        if num % i == 0:
            if is_prime(i):
                prime_factors.append(i)
            if is_prime(num / i):
                prime_factors.append(i)
    print("Largest prime factor is {}".format(max(prime_factors)))

prime_factors(600851475143)
