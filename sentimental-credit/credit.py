# TODO
import re
import sys


def main():
    # Prompt for input
    number = input("Number: ")

    # Check for conditions compliance
    if re.fullmatch("3[47]\d{13}", number) and check(number):
        print("AMEX")
        sys.exit(0)
    elif re.fullmatch("5[1-5]\d{14}", number) and check(number):
        print("MASTERCARD")
        sys.exit(0)
    elif (re.fullmatch("4\d{12}", number) or re.fullmatch("4\d{15}", number)) and check(
        number
    ) == True:
        print("VISA")
        sys.exit(0)
    else:
        print("INVALID")


# Check for accomplishment of the Luhn algorithm
def check(number):
    # Append the digits of the number to the list, starting from the end
    digits = list()
    for digit in reversed(number):
        digits.append(int(digit))

    # Calculate the summ of digits using the Luhn algorithm
    sum = 0
    for i in range(1, len(digits), 2):
        digit = digits[i]
        digit *= 2
        if digit > 9:
            sum += (digit // 10) + (digit % 10)
        else:
            sum += digit
    for i in range(0, len(digits), 2):
        digit = digits[i]
        sum += digit

    # Return the value by the last digit of the summ
    if sum % 10 == 0:
        return True
    else:
        return False


main()
