import sqlite3

def connection():
    con=sqlite3.connect("student19.db")
    return con

def create(con):
    cur=con.cursor()
    cur.execute("create table Students(id integer,name text,age integer,course text);")
    con.close()

def insert(con):
    cur=con.cursor()
    cur.executescript("""
    insert into Students values(17,"Abd",25,"BTech");
    insert into Students values(18,"Virat",24,"MBA");
    insert into Students values(19,"Teja",22,"MMA");
    """)
    con.commit()
    con.close()

def read(con):
    cur=con.cursor()
    cur.execute("select * from Students")
    data=cur.fetchall()
    for d in data:
        print(d)
    con.close()

def delete(con):
    cur=con.cursor()
    cur.execute("select * from Students")
    data=cur.fetchall()
    id=int(input("enter id to delete :"))
    cur.execute('delete from Students where id = ?',(id,))
    con.commit()
    cur.execute("select * from Students")
    print("details after delete")
    data=cur.fetchall()
    for d in data:
        print(d)
    con.close()

def update(con):
    cur = con.cursor()
    cur.execute("select * from Students")
    print("details before update")
    data = cur.fetchall()
    for i in data:
        print(i)
    id = int(input("enter id  :"))
    name=input("enter changed name to update : ")
    cur.execute('update Students set name=? where id = ?', (name,id))
    con.commit()
    cur.execute("select * from Students")
    print("details after update")
    data = cur.fetchall()
    for d in data:
        print(d)
    con.close()


con=connection()
create(con)

con=connection()
insert(con)
#display
con=connection()
read(con)
#delete
con=connection()
delete(con)
#update
con=connection()
update(con)