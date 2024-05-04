from validator_collection import checkers


if checkers.is_email(input("What's your email adress? ")):
    print("Valid")
else:
    print("Invalid")
