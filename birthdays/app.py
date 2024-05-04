import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        name = request.form.get("name")
        month = request.form.get("month")
        day = request.form.get("day")

        if not name:
            return "Must provide name", 400

        elif not month:
            return "Must provide month", 400

        elif int(month) < 1 or int(month) > 12:
            return "Month must be positive integer between 1 and 12", 400

        elif not day:
            return "Must provide day", 400

        elif int(day) < 1 or int(day) > 31:
            return "Day must be positive integer between 1 and 31", 400

        db.execute(
            "INSERT INTO birthdays(name, month, day) " "VALUES (?, ?, ?)",
            name,
            month,
            day,
        )

        return redirect("/")

    else:
        birthdays = db.execute("SELECT name, month, day FROM birthdays")
        print(birthdays)

        return render_template("index.html", birthdays=birthdays)
