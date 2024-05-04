# TODO
# Declare variables
l, s, w = 0, 0, 1

# Prompt for input
text = input("Text: ")

# Count the number of letters, words, and sentences
for c in text:
    if c == " ":
        w += 1
    elif c in [".", "!", "?"]:
        s += 1
    elif c.isalpha():
        l += 1

# Count the number of letters and sentences per 100 words
l = l / (w / 100)
s = s / (w / 100)

# Calculate index
i = round(0.0588 * l - 0.296 * s - 15.8)

# Print index
if i < 1:
    print("Before Grade 1")
elif i > 16:
    print("Grade 16+")
else:
    print(f"Grade {i}")
