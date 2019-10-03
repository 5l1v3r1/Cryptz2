#!/usr/bin/env python3
# Created by benelhaj_younes (Do0pH2ck)
# This Section to verify db (database)

import sqlite3

def login():
    for i in range(1):
        password = input("Enter licensekey: ")
        with sqlite3.connect('store.db') as db:
            c = db.cursor()
        catch_pass = ("SELECT * FROM passman WHERE licensekey = ?")
        c.execute(catch_pass, [(password)])
        result = c.fetchall()

        if result:
            for i in result:
                print("Correct LicenseKey ")
                break
        else:
            print("Uncorrect: ")
            break
if __name__ == '__main__':
    login()
