-- Keep a log of any SQL queries you execute as you solve the mystery.

.tables

-- Get crime scene report
.schema crime_scene_reports
SELECT description FROM crime_scene_reports
WHERE year = 2021 AND month = 7 AND day = 28
AND street = "Humphrey Street";

-- Get interviews
.schema interviews
SELECT name, transcript FROM interviews
WHERE year = 2021 AND month = 7 AND day = 28
AND transcript LIKE "%bakery%";

-- Get license plates
.schema bakery_security_logs
SELECT license_plate FROM bakery_security_logs
WHERE year = 2021 AND month = 7 AND day = 28
AND hour = 10 AND minute >= 15 AND minute <= 25
AND activity = "exit";

-- Get bank account numbers
.schema atm_transactions
SELECT account_number FROM atm_transactions
WHERE year = 2021 AND month = 7 AND day = 28
AND atm_location = "Leggett Street"
AND transaction_type = "withdraw";

-- Get person ids
.schema bank_accounts
SELECT person_id  FROM bank_accounts
WHERE account_number IN
(SELECT account_number FROM atm_transactions
WHERE year = 2021 AND month = 7 AND day = 28
AND atm_location = "Leggett Street"
AND transaction_type = "withdraw");

-- Get phone numbers
.schema phone_calls
SELECT caller FROM phone_calls
WHERE year = 2021 AND month = 7 AND day = 28
AND duration < 60;

-- Get airport id
.schema airports
SELECT id FROM airports WHERE city = "Fiftyville";

-- Get flight id
.schema flights
SELECT id FROM flights WHERE
origin_airport_id =
(SELECT id FROM airports WHERE city = "Fiftyville")
AND year = 2021 AND month = 7 AND day = 29
ORDER BY hour, minute LIMIT 1;

-- Get passport numbers
.schema passengers
SELECT passport_number FROM passengers
WHERE flight_id =
(SELECT id FROM flights WHERE
origin_airport_id =
(SELECT id FROM airports WHERE city = "Fiftyville")
AND year = 2021 AND month = 7 AND day = 29
ORDER BY hour, minute LIMIT 1);

-- Get thief name
SELECT name FROM people WHERE
license_plate IN
(SELECT license_plate FROM bakery_security_logs
WHERE year = 2021 AND month = 7 AND day = 28
AND hour = 10 AND minute >= 15 AND minute <= 25
AND activity = "exit")
AND id IN
(SELECT person_id  FROM bank_accounts
WHERE account_number IN
(SELECT account_number FROM atm_transactions
WHERE year = 2021 AND month = 7 AND day = 28
AND atm_location = "Leggett Street"
AND transaction_type = "withdraw"))
AND phone_number IN
(SELECT caller FROM phone_calls
WHERE year = 2021 AND month = 7 AND day = 28
AND duration < 60)
AND passport_number IN
(SELECT passport_number FROM passengers
WHERE flight_id =
(SELECT id FROM flights WHERE
origin_airport_id =
(SELECT id FROM airports WHERE city = "Fiftyville")
AND year = 2021 AND month = 7 AND day = 29
ORDER BY hour, minute LIMIT 1));

-- Get city where thief escaped to
select city FROM airports
WHERE id =
(SELECT destination_airport_id FROM flights WHERE
origin_airport_id =
(SELECT id FROM airports WHERE city = "Fiftyville")
AND year = 2021 AND month = 7 AND day = 29
ORDER BY hour, minute LIMIT 1);

-- Get accomplice name
SELECT name FROM people WHERE phone_number =
(SELECT receiver FROM phone_calls
WHERE year = 2021 AND month = 7 AND day = 28
AND duration < 60 AND caller =
(SELECT phone_number FROM people WHERE name =
(SELECT name FROM people WHERE
license_plate IN
(SELECT license_plate FROM bakery_security_logs
WHERE year = 2021 AND month = 7 AND day = 28
AND hour = 10 AND minute >= 15 AND minute <= 25
AND activity = "exit")
AND id IN
(SELECT person_id  FROM bank_accounts
WHERE account_number IN
(SELECT account_number FROM atm_transactions
WHERE year = 2021 AND month = 7 AND day = 28
AND atm_location = "Leggett Street"
AND transaction_type = "withdraw"))
AND phone_number IN
(SELECT caller FROM phone_calls
WHERE year = 2021 AND month = 7 AND day = 28
AND duration < 60)
AND passport_number IN
(SELECT passport_number FROM passengers
WHERE flight_id =
(SELECT id FROM flights WHERE
origin_airport_id =
(SELECT id FROM airports WHERE city = "Fiftyville")
AND year = 2021 AND month = 7 AND day = 29
ORDER BY hour, minute LIMIT 1)))));
