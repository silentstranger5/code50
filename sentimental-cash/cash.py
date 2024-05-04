# TODO
from cs50 import get_float

# Prompt for input and check for conditions
while True:
    cash = get_float("Change owed: ")
    if cash >= 0:
        break

# Count the number of the coins
coins = 0
while cash >= 0.25:
    cash = round(cash - 0.25, 2)
    coins += 1
while cash >= 0.1:
    cash = round(cash - 0.1, 2)
    coins += 1
while cash >= 0.05:
    cash = round(cash - 0.05, 2)
    coins += 1
while cash >= 0.01:
    cash = round(cash - 0.01, 2)
    coins += 1

# Print the number of the coins
print(coins)
