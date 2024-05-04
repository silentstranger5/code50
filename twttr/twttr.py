s = input("Input: ")
print("Output: ", end="")
for c in s:
    if c.lower() not in "aeiou":
        print(c, end="")
print()
