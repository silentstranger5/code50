from os.path import splitext
from PIL import Image, ImageOps
import sys

if len(sys.argv) < 3:
    sys.exit("Too few command-line arguments")
elif len(sys.argv) > 3:
    sys.exit("Too many command-line arguments")

extensions = [".jpg", ".jpeg", ".png"]
infilext = splitext(sys.argv[1])[1].lower()
outfilext = splitext(sys.argv[2])[1].lower()

if not infilext in extensions:
    sys.exit("Invalid input")
elif not outfilext in extensions:
    sys.exit("Invalid output")
elif not (infilext == outfilext):
    sys.exit("Input and output have different extensions")

try:
    photo = Image.open(sys.argv[1])
except FileNotFoundError:
    sys.exit("File does not exist")

shirt = Image.open("shirt.png")
photo = Image.open(sys.argv[1])

photo = ImageOps.fit(photo, shirt.size)
photo.paste(shirt, mask=shirt)
photo.save(sys.argv[2])
