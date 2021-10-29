import socket
from thread import *
import time

client = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
client.connect(('localhost',8180))

def accept_msg(sock):
	while True:
		msg = sock.recv(1024)
		if(msg):
			print(msg)
		time.sleep(1)

def send_msg(sock):
	while True:
		time.sleep(1)
		msg = raw_input(":")
		sock.send(msg)

while True:
	start_new_thread(accept_msg,(client,))
	start_new_thread(send_msg,(client,))

