# TODO
from cs50 import get_int

# Prompt for input and check for conditions
while True:
    height = get_int("Height: ")
    if height >= 1 and height <= 8:
        break

# Print double half-pyramid
for i in range(height):
    print(" " * (height - (i + 1)), end="")
    print("#" * (i + 1), end="")
    print(" " * 2, end="")
    print("#" * (i + 1), end="")
    print()
