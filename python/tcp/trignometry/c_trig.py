import socket
import math
client = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
client.connect(('localhost',6363))

while True:
	option = raw_input("1.sin 2.con 3.tan")
	client.send(option)
	angle_degree = raw_input("Enter angle")
	angle =	math.radians(int(angle_degree)) 
	client.send(str(angle))
	print(client.recv(1024))
