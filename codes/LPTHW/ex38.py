#!/usr/bin/env python3
"""
Doing Things to Lists ex38
"""

ten_things = "Apples Oranges Crows Telephone Light Sugar"

print("Wait there are not 10 things in that list. Let's fix that.")

stuff = ten_things.split(' ')
more_stuff = ["Day", "Night", "Song", "Frisbee", "Corn", "Banana", "Girl", "Boy"]

while len(stuff) != 10:
    next_one = more_stuff.pop()
    print("Adding: ", next_one)
    stuff.append(next_one)
    print(f"There are {len(stuff)} items now.")

print("There we go: ", stuff)

print("Let's do some things with stuff.")

print(stuff[1])
print(stuff[-1]) # whoa! fancy, print last item
print(stuff.pop()) # same as above output
print(' '.join(stuff)) # what? cool!, yes print all as a line spaced with a space
print('#'.join(stuff[3:5])) # super stellar!, join from index 3 to 5 separated with a hash pound
