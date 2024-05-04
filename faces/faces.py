def main():
    print(convert(input()))


def convert(str):
    return str.replace(":)", "🙂").replace(":(", "🙁")


main()
