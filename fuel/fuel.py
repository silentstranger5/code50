while True:
    fraction = input("Fraction: ").partition("/")
    try:
        x = int(fraction[0])
        y = int(fraction[2])
        fuel = round(100 * (x / y))
        if fuel > 100:
            continue
    except (ValueError, ZeroDivisionError):
        pass
    else:
        break
if fuel <= 1:
    print("E")
elif fuel >= 99:
    print("F")
else:
    print(f"{fuel}%")
