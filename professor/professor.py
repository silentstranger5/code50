import random


def main():
    score = 0
    level = get_level()
    for i in range(10):
        x = generate_integer(level)
        y = generate_integer(level)
        answer = x + y
        for i in range(3):
            try:
                guess = int(input(f"{x} + {y} = "))
            except ValueError:
                print("EEE")
            else:
                if guess != answer:
                    print("EEE")
                else:
                    score += 1
                    break
        else:
            print(f"{x} + {y} = {answer}")
    print(f"Score: {score}")


def get_level():
    while True:
        try:
            level = int(input("Level: "))
        except ValueError:
            continue
        else:
            if level not in range(1, 4):
                continue
            else:
                return level


def generate_integer(level):
    if level == 1:
        lower = 0
    else:
        lower = (10 ** (level - 1))
    upper = (10 ** level) - 1

    return random.randint(lower, upper)


if __name__ == "__main__":
    main()