import csv
import sqlite3

assignments = list()
house_id = 1
houses = list()
houses_list = list()
houses_set = set()
students = list()

with open("students.csv") as file:
    reader = csv.DictReader(file)
    for row in reader:
        students.append((int(row["id"]), row["student_name"]))
        if row["house"] not in houses_set:
            houses_set.add(row["house"])
            houses_list.append([row["house"], row["head"]])

houses_list = sorted(houses_list)
for house in houses_list:
    house.insert(0, house_id)
    house_id += 1
    house = tuple(house)
    houses.append(house)

with open("students.csv") as file:
    reader = csv.DictReader(file)
    for row in reader:
        for house in houses:
            if row["house"] in house:
                assignments.append((int(row["id"]), house[0]))

con = sqlite3.connect("roster.db")
cur = con.cursor()

cur.execute("DROP TABLE students")
cur.execute("CREATE TABLE students(id, student_name)")
cur.execute("CREATE TABLE houses(id, house_name, head)")
cur.execute("CREATE TABLE assignments(student_id, house_id)")
cur.executemany("INSERT INTO students VALUES(?, ?)", students)
cur.executemany("INSERT INTO houses VALUES(?, ?, ?)", houses)
cur.executemany("INSERT INTO assignments VALUES(?, ?)", assignments)

con.commit()
con.close()
