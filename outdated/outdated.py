months = [
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
]
while True:
    try:
        date = input("Date: ")
        if date.find('/') != -1:
            month, day, year = date.split('/')
            month = int(month)
            day = int(day)
            year = int(year)
        elif date.find(' ') != -1:
            month, day, year = date.split(' ')
            if not day.endswith(','):
                continue
            day = day.removesuffix(',')
            month = months.index(month) + 1
            day = int(day)
            year = int(year)
        if day > 31 or month > 12:
            continue
    except:
        pass
    else:
        break
print(f"{year}-{month:02}-{day:02}")
