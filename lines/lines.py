import sys

if len(sys.argv) < 2:
    sys.exit("Too few command-line arguments")
elif len(sys.argv) > 2:
    sys.exit("Too many command-line arguments")
elif not sys.argv[1].endswith(".py"):
    sys.exit("Not a python file")

try:
    file = open(sys.argv[1])
except FileNotFoundError:
    sys.exit("File does not exist")

lines = 0
for line in file:
    line = line.lstrip()
    if len(line) > 0 and not line.startswith("#"):
        lines += 1

file.close()

print(lines)
