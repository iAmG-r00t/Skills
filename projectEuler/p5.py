#!/usr/bin/env python3
"""
Problem 5; Smallest multiple
"""

import numpy as np

smallest = np.lcm.reduce(range(1,21))

print(f"The smallest positive number that is evenly divisible by all the numbers from 1 to 20 is {smallest}")
