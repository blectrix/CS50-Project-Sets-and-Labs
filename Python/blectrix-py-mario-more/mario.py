# TODO
from cs50 import get_int

# Prompting user the number of blocks to build
print("Please enter a number 1 - 8 to build.")
# Getting height.
h = 0
# Do this function if entered value is between 1 - 8

while 1 > h or h > 8:
    h = get_int("Height: ")
# Build.
for row in range(1, (h + 1), 1):
    print(" " * (h - row), end="")
    print("#" * row, end="")
    print(" " * 2, end="")
    print("#" * row, end="")
    print("")