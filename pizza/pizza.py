import csv
import sys
import tabulate

if len(sys.argv) < 2:
    sys.exit("Too few command-line arguments")
elif len(sys.argv) > 2:
    sys.exit("Too many command-line arguments")
elif not sys.argv[1].endswith(".csv"):
    sys.exit("Not a CSV file")

try:
    file = open(sys.argv[1])
except FileNotFoundError:
    sys.exit("File does not exist")

table = list()
reader = csv.reader(file)
for row in reader:
    table.append([row[0], row[1], row[2]])

print(tabulate.tabulate(table[1:], headers=table[0], tablefmt="grid"))

file.close()
