def main():
    print(shorten(input()))


def shorten(word):
    chars = "aeiou"
    for char in word:
        if char.lower() in chars:
            word = word.replace(char, "")
    return word


if __name__ == "__main__":
    main()
