import socket
import sys


server = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

server.sendto("hi",('localhost',5656))

file_name,arr = server.recvfrom(1024)

fie = file_name.strip()

f = open(fie,"wb")

data,arr = server.recvfrom(1024)

while data != "@#$":
	f.write(data)
	data,arr = server.recvfrom(1024)
f.close()
server.close
