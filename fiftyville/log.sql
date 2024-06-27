-- Keep a log of any SQL queries you execute as you solve the mystery.

--Who the thief is,
--What city the thief escaped to, and
--Who the thief’s accomplice is who helped them escape
--All you know is that the theft took place on July 28, 2023 and that it took place on Humphrey Street.


SELECT * FROM crime_scene_reports;
SELECT * FROM crime_scene_reports WHERE month = 7 AND day = 28 AND year = 2023 AND street LIKE '%Humphrey Street%';
--Took place at 10:15, 3 witnesses, each of them mention the bakery (get query for interviews that mention bakery)

SELECT * FROM interviews WHERE transcript LIKE '%Bakery%' AND NOT name = 'Kiana';
--Ruth, Eugene, and Raymond are the witnesses.

-- query for cars in the bakery parking lot within 10 minutes of the theft
SELECT license_plate, activity FROM bakery_security_logs WHERE month = 7 AND day = 28 AND year = 2023 AND hour = 10 AND minute >= 15 AND minute <=25;
SELECT * FROM people WHERE license_plate = (SELECT license_plate FROM bakery_security_logs WHERE month = 7 AND day = 28 AND year = 2023 AND hour = 10 AND minute >= 15 AND minute <=25);
--5P2BI95 = Vanessa | (725) 555-4692 | 2963008352
--94KL13X = Bruce | (367) 555-5533 | 5773159633
--6P58WS2 = Barry | (301) 555-4174 | 7526138472
--4328GD8 = Luca | (389) 555-5198 | 8496433585
--G412CB7 = Sofia | (130) 555-0289 | 1695452385
--L93JTIZ = Iman | (829) 555-5269 | 7049073643
--322W7JE = Diana | (770) 555-1861 | 3592750733
--0NTHK55 = Kelsey | (499) 555-9472 | 8294398571

-- query for Leggett Street ATM where thief withdrew money (morning)
SELECT atm_location FROM atm_transactions;
SELECT * FROM atm_transactions WHERE month = 7 AND day = 28 AND year = 2023 AND atm_location LIKE '%Leggett%' AND transaction_type = 'withdraw';
SELECT name FROM people JOIN bank_accounts on bank_accounts.person_id = people.id WHERE account_number = (SELECT account_number FROM atm_transactions WHERE month = 7 AND day = 28 AND year = 2023 AND atm_location LIKE '%Leggett%' AND transaction_typ
e = 'withdraw');
-- Prime suspects are Bruce, Diana

-- query for phone calls less than a minute after the thief left the bakery.
SELECT * FROM phone_calls
SELECT * FROM phone_calls WHERE month = 7 AND day = 28 AND year = 2023 AND duration < 60;
-- Prime suspects are Bruce, Diana


-- Bruce accomplice is (375) 555-8161  AKA ROBIN
SELECT * FROM people WHERE phone_number = '(375) 555-8161';
-- find out the earliest flight out of fiftyville purchased by the other person on the other end of the call

SELECT * FROM flights
JOIN passengers ON passengers.flight_id = flights.id
WHERE passport_number = ????? AND month = 7 AND day = 28 AND year = 2023;

-- Bruce is THE suspect

+----+-------------------+------------------------+------+-------+-----+------+--------+-----------+-----------------+------+
| id | origin_airport_id | destination_airport_id | year | month | day | hour | minute | flight_id | passport_number | seat |
+----+-------------------+------------------------+------+-------+-----+------+--------+-----------+-----------------+------+
| 36 | 8                 | 4                      | 2023 | 7     | 29  | 8    | 20     | 36        | 5773159633      | 4A   |
+----+-------------------+------------------------+------+-------+-----+------+--------+-----------+-----------------+------+

SELECT * FROM airports WHERE id = 4;
-- Bruce went to New York on the 29th

