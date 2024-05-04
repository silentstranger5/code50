import re
import sys


def main():
    print(convert(input("Hours: ")))


def convert(s):
    if not (
        hours := re.fullmatch(
            r"(\d{1,2})(:\d{1,2})? (AM|PM) to (\d{1,2})(:\d{1,2})? (AM|PM)", s
        )
    ):
        raise ValueError

    time_from = standart(hours.group(1), hours.group(2), hours.group(3))
    time_to = standart(hours.group(4), hours.group(5), hours.group(6))
    return time_from + " to " + time_to


def standart(hour, minute, mode):
    hour = int(hour)
    if minute:
        minute = int(minute.removeprefix(":"))
    else:
        minute = 0
    if hour > 12 or minute > 59:
        raise ValueError
    if mode == "PM":
        if hour < 12:
            hour += 12
    elif mode == "AM":
        if hour == 12:
            hour = 0

    return f"{hour:02}:{minute:02}"

if __name__ == "__main__":
    main()
