
#!/usr/bin/env python3
# Created By benelhaj_younes (Do0pH2ck)
import sqlite3
with sqlite3.connect('store.db') as db:
    c = db.cursor()

c.execute('''
CREATE TABLE IF NOT EXISTS passman(
userID INTERGER PRIMARY KEY,
licensekey);
''')
## Values: 911032165469755
c.execute('INSERT INTO passman(licensekey) VALUES("?")')

db.commit()

c.execute("SELECT * FROM passman")
print(c.fetchall())
