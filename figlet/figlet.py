from pyfiglet import Figlet
import random
import sys

figlet = Figlet()

if (
    len(sys.argv) == 3
    and sys.argv[1] in ["-f", "--font"]
    and sys.argv[2] in figlet.getFonts()
):
    f = sys.argv[2]
elif len(sys.argv) == 1:
    f = random.choice(figlet.getFonts())
else:
    sys.exit("Invalid usage")

figlet.setFont(font=f)
s = input("Input: ")
print("Output:", figlet.renderText(s), sep="\n")
