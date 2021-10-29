import socket
from thread import *
import time

server = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
server.bind(('localhost',8180))

server.listen(10)

print("waiting for client")

sock,arr = server.accept()

def accept_msg(sock):
	while True:
		time.sleep(1)
		msg = sock.recv(1024)
		if(msg):
			print(msg)

def send_msg(sock):
	while True:
		msg = raw_input(":")
		sock.send(msg)
	time.sleep(1)

print("connected client :",arr)
while True:
	start_new_thread(accept_msg,(sock,))
	start_new_thread(send_msg,(sock,))




