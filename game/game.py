import random

while True:
    try:
        n = int(input("Level: "))
        number = random.randint(1, n)
    except ValueError:
        continue
    else:
        break

while True:
    try:
        guess = int(input("Guess: "))
    except ValueError:
        continue
    else:
        if guess < 1:
            continue
        elif guess < number:
            print("Too small!")
        elif guess > number:
            print("Too large!")
        else:
            print("Just right!")
            break
