items = {}
while True:
    try:
        item = input().upper()
    except EOFError:
        print()
        items = {item: items[item] for item in sorted(items)}
        for item in items:
            print(items[item], item)
        break
    else:
        if item in items:
            items[item] += 1
        else:
            items[item] = 1
