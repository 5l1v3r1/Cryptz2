#!/usr/bin/env python3
# Created by benelhaj_younes (Do0pH2ck)
## This Section To Create One licensekey and add it to db 

import random
import sqlite3
import os
import sys

gene = random.randint(1, 999999999999999)


print(gene)
with sqlite3.connect('store.db') as db:
    conn = db.cursor()
conn.execute('INSERT INTO passman(licensekey) VALUES("{}")'.format(gene))
db.commit()
conn.execute("SELECT * FROM passman")
print(conn.fetchall())
