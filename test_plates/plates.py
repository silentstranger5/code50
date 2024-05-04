def main():
    if is_valid(input("Plate: ")):
        print("Valid")
    else:
        print("Invalid")


def is_valid(s):
    if len(s) > 6 or len(s) < 2:
        return False
    if not (s[0].isalpha() and s[1].isalpha()):
        return False
    for c in s:
        if not c.isalnum():
            return False
        if c.isdigit():
            if c == "0":
                return False
            for d in s[s.find(c) :]:
                if not d.isdigit():
                    return False
            break
    return True


if __name__ == "__main__":
    main()
