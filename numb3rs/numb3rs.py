import re
import sys


def main():
    print(validate(input("IPv4 Address: ")))


def validate(ip):
    if adress := re.fullmatch(r"(\d{1,3})\.(\d{1,3})\.(\d{1,3})\.(\d{1,3})", ip):
        for number in adress.groups():
            number = int(number)
            if not 0 <= number <= 255:
                return False
        else:
            return True
    else:
        return False


if __name__ == "__main__":
    main()
