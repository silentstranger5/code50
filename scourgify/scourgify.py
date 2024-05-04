import csv
import sys

if len(sys.argv) < 3:
    sys.exit("Too few command-line arguments")
elif len(sys.argv) > 3:
    sys.exit("Too many command-line arguments")

try:
    file = open(sys.argv[1])
except FileNotFoundError:
    sys.exit(f"Could not open {sys.argv[1]}")

data = list()
reader = csv.DictReader(file)
for row in reader:
    data.append({"name": row["name"], "house": row["house"]})

for i in range(len(data)):
    name = data[i]["name"].split(", ")
    data[i] = {"first": name[1], "last": name[0], "house": data[i]["house"]}

file.close()

file = open(sys.argv[2], "w")
fieldnames = ["first", "last", "house"]
writer = csv.DictWriter(file, fieldnames=fieldnames)
writer.writeheader()

for row in data:
    writer.writerow({"first": row["first"], "last": row["last"], "house": row["house"]})

file.close()
