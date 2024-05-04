import requests
import sys

try:
    response = requests.get("https://api.coindesk.com/v1/bpi/currentprice.json")
except requests.RequestException:
    sys.exit("Request failed")

response = response.json()
price = response["bpi"]["USD"]["rate_float"]

try:
    amount = float(sys.argv[1]) * price
except IndexError:
    sys.exit("Missing command-line argument")
except ValueError:
    sys.exit("Command-line argument is not a number")
else:
    print(f"${amount:,.4f}")