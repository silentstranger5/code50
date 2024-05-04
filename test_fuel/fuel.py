def main():
    print(gauge(convert(input())))


def convert(fraction):
    x = int(fraction.partition('/')[0])
    y = int(fraction.partition('/')[2])
    if y == 0:
        raise ZeroDivisionError
    if x > y:
        raise ValueError
    return round(100 * (x / y))


def gauge(percentage):
    if percentage <= 1:
        return "E"
    if percentage >= 99:
        return "F"
    return f"{percentage}%"


if __name__ == "__main__":
    main()
