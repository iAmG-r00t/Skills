#!/usr/bin/env python3
"""
Printing, Printing ex8
"""

formatter = "{} {} {} {}"

print(formatter.format(1, 2, 3, 4))
print(formatter.format("one", "two", "three", "four"))
print(formatter.format(True, False, False, True))
print(formatter.format(formatter, formatter, formatter, formatter))
print(formatter.format(
    "Gr00t",
    "is learning",
    "Python",
    "the HardWay and enjoying it."
    ))
