import csv
import requests


def main():
    # Read NYTimes Covid Database
    download = requests.get(
        "https://raw.githubusercontent.com/nytimes/covid-19-data/master/us-states.csv"
    )
    decoded_content = download.content.decode("utf-8")
    file = decoded_content.splitlines()
    reader = csv.DictReader(file)

    # Construct 14 day lists of new cases for each states
    new_cases = calculate(reader)

    # Create a list to store selected states
    states = []
    print("Choose one or more states to view average COVID cases.")
    print("Press enter when done.\n")

    while True:
        state = input("State: ")
        if state in new_cases:
            states.append(state)
        if len(state) == 0:
            break

    print(f"\nSeven-Day Averages")

    # Print out 7-day averages for this week vs last week
    comparative_averages(new_cases, states)


# TODO: Create a dictionary to store 14 most recent days of new cases by state
def calculate(reader):
    previous_cases = dict()
    for row in reader:
        state = row["state"]
        cases = row["cases"]
        if state in previous_cases:
            previous_cases[state].append(cases)
            if len(previous_cases[state]) > 15:
                previous_cases[state].pop(0)
        else:
            previous_cases[state] = list()

    new_cases = dict()
    for state in previous_cases:
        cases = previous_cases[state]
        new_cases[state] = list()
        for i in range(1, len(cases)):
            new_cases[state].append(int(cases[i]) - int(cases[i - 1]))
    return new_cases


# TODO: Calculate and print out seven day average for given state
def comparative_averages(new_cases, states):
    for state in states:
        first_week = sum(new_cases[state][0:7]) / 7
        second_week = sum(new_cases[state][7:14]) / 7
        try:
            percent = round((second_week - first_week) / second_week * 100)
            if percent > 0:
                difference = "an increase"
            else:
                difference = "a decrease"
            print(
                f"{state} had a 7-day average of {round(second_week)} and {difference} of {abs(percent)}%."
            )
        except ZeroDivisionError:
            print(
                f"{state} had a 7-day average of {round(second_week)} and an increase of 100%."
            )


main()
