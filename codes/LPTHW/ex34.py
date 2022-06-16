#!/usr/bin/env python3
"""
Accessing Elements of Lists ex34
"""

animals = ['bear', 'tiger', 'penguin', 'zebra']

# manual picking
bear = animals[0]
tiger = animals[1]
penguin = animals[2]
zebra = animals[3]

# for loop bit
for animal in animals:
    print("Animal: {} is at index {}".format(animal, animals.index(animal)))
