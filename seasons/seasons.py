from datetime import date
import inflect
import sys


def main():
    print(convert(input("Date of birth: ")))


def convert(s):
    try:
        birth = date.fromisoformat(s)
    except (TypeError, ValueError):
        sys.exit("Invalid date")

    minutes = round((date.today() - birth).total_seconds() / 60)
    minutes = inflect.engine().number_to_words(minutes)
    minutes = minutes.replace(" and", "")
    minutes = minutes.capitalize()
    minutes = minutes + " minutes"

    return minutes


if __name__ == "__main__":
    main()
