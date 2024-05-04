import inflect

names = list()
while True:
    try:
        name = input("Name: ")
    except EOFError:
        print()
        break
    else:
        names.append(name)
print("Adieu, adieu, to", inflect.engine().join(names))