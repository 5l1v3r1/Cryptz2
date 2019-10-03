#!/usr/bin/env python3
# Created by benelhaj_younes (Do0pH2ck)
# This Section is to make a connection with database

import sqlite3

def create_connection(db_file):
    try:
        conn = sqlite3.connect(db_file)
        print(sqlite3.version)
    except Error as e:
        print(e)
    finally:
        conn.close()


if __name__ == '__main__':
    create_connection("/home/younes/Scripts/Project6/store.db")
