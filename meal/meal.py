def main():
    time = convert(input("What time is it? "))
    if 7.0 <= time <= 8.0:
        print("breakfast time")
    elif 12.0 <= time <= 13.0:
        print("lunch time")
    elif 18.0 <= time <= 19.0:
        print("dinner time")


def convert(time):
    if time.find(" ") != -1:
        time, period = time.split(" ")
    else:
        period = "not set"

    hours, minutes = time.split(":")
    hours = int(hours)
    minutes = int(minutes)

    if period == "p.m.":
        hours = hours + 12

    return float(hours + (minutes / 60))


if __name__ == "__main__":
    main()
