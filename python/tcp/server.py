import socket
import sys
import select
from thread import *

server = socket.socket(socket.AF_INET,socket.SOCK_STREAM)

server.bind(('127.0.0.1',8380))
server.listen(10)
list_c = []
print("CHAT SERVER")

def connect_client(conn,addr):

	conn.send("Welcome to Chat Room")

	while True:

		try:
			msg = con.recv(1024)

			if msg:
				print(addr[0] , " ",msg)
				broadcast(conn,msg)
		except:	
			continue

def broadcast(conn,msg):
	for c in list_c:
		if c != conn:
			c.send(msg)


print ("here")
while True:
	conn,arr = server.accept() 
	list_c.append(conn)
	print(" Connected",arr[0])
	start_new_thread(connect_client,(conn,arr))
conn.close()
server.close()

