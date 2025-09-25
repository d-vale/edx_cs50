-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Starting with what we know: theft on July 28, 2024 on Humphrey Street
-- Step 1: Find the crime scene report
SELECT
    description
FROM
    crime_scene_reports
WHERE
    YEAR = 2024
    AND MONTH = 7
    AND DAY = 28
    AND street = 'Humphrey Street';

-- Step 2: Get witness testimonies from that day
SELECT
    name,
    transcript
FROM
    interviews
WHERE
    YEAR = 2024
    AND MONTH = 7
    AND DAY = 28;

-- Step 3: Check cars leaving courthouse parking (within 10 minutes of theft)
SELECT
    name,
    courthouse_security_logs.license_plate
FROM
    people
    JOIN courthouse_security_logs ON people.license_plate = courthouse_security_logs.license_plate
WHERE
    courthouse_security_logs.year = 2024
    AND courthouse_security_logs.month = 7
    AND courthouse_security_logs.day = 28
    AND courthouse_security_logs.hour = 10
    AND courthouse_security_logs.minute >= 15
    AND courthouse_security_logs.minute <= 25
    AND activity = 'exit';

-- Step 4: Check ATM withdrawals on Leggett Street that morning
SELECT
    name,
    atm_transactions.amount
FROM
    people
    JOIN bank_accounts ON people.id = bank_accounts.person_id
    JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
WHERE
    atm_transactions.year = 2024
    AND atm_transactions.month = 7
    AND atm_transactions.day = 28
    AND atm_transactions.atm_location = 'Leggett Street'
    AND atm_transactions.transaction_type = 'withdraw';

-- Step 5: Find intersection of both clues (car + ATM)
-- People who both left courthouse AND withdrew money
SELECT
    name
FROM
    people
WHERE
    name IN (
        SELECT
            name
        FROM
            people
            JOIN courthouse_security_logs ON people.license_plate = courthouse_security_logs.license_plate
        WHERE
            courthouse_security_logs.year = 2024
            AND courthouse_security_logs.month = 7
            AND courthouse_security_logs.day = 28
            AND courthouse_security_logs.hour = 10
            AND courthouse_security_logs.minute >= 15
            AND courthouse_security_logs.minute <= 25
            AND activity = 'exit'
    )
    AND name IN (
        SELECT
            name
        FROM
            people
            JOIN bank_accounts ON people.id = bank_accounts.person_id
            JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
        WHERE
            atm_transactions.year = 2024
            AND atm_transactions.month = 7
            AND atm_transactions.day = 28
            AND atm_transactions.atm_location = 'Leggett Street'
            AND atm_transactions.transaction_type = 'withdraw'
    );

-- Step 6: Check phone calls less than 1 minute on July 28
SELECT
    name,
    phone_calls.caller,
    phone_calls.receiver
FROM
    people
    JOIN phone_calls ON people.phone_number = phone_calls.caller
WHERE
    phone_calls.year = 2024
    AND phone_calls.month = 7
    AND phone_calls.day = 28
    AND phone_calls.duration < 60
    AND people.name IN ('Bruce', 'Diana', 'Iman', 'Luca');

-- Step 7: Find the earliest flight out of Fiftyville on July 29
SELECT
    flights.id,
    full_name,
    city,
    flights.hour,
    flights.minute
FROM
    airports
    JOIN flights ON airports.id = flights.destination_airport_id
WHERE
    flights.origin_airport_id = (
        SELECT
            id
        FROM
            airports
        WHERE
            city = 'Fiftyville'
    )
    AND flights.year = 2024
    AND flights.month = 7
    AND flights.day = 29
ORDER BY
    flights.hour,
    flights.minute
LIMIT
    1;

-- Step 8: Check who from our suspects took this flight
SELECT
    name
FROM
    people
    JOIN passengers ON people.passport_number = passengers.passport_number
    JOIN flights ON passengers.flight_id = flights.id
WHERE
    flights.year = 2024
    AND flights.month = 7
    AND flights.day = 29
    AND flights.hour = 8
    AND flights.minute = 20
    AND people.name IN ('Bruce', 'Diana', 'Luca');

-- Step 9: Find Bruce's accomplice (who he called)
SELECT
    name
FROM
    people
WHERE
    phone_number = (
        SELECT
            receiver
        FROM
            phone_calls
        WHERE
            caller = (
                SELECT
                    phone_number
                FROM
                    people
                WHERE
                    name = 'Bruce'
            )
            AND YEAR = 2024
            AND MONTH = 7
            AND DAY = 28
            AND duration < 60
    );
