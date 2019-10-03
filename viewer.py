#!/usr/bin/env python3
# Created by Benelhaj_younes (Do0pH2ck)
# This Section to Show License Key's Available in db 

import sqlite3

with sqlite3.connect('store.db') as db:
    connect1 = db.cursor()

connect1.execute("SELECT * FROM passman")
print(connect1.fetchall())
