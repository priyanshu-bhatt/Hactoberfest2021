import socket
import sys


server = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
server.bind(('192.168.0.109',5656))

conn,arr = server.recvfrom(1024)
print(arr)

file_name = sys.argv[1]
print(file_name," file")
server.sendto(file_name,arr)

f = open(file_name,'rb')

data = f.read(1024)
while data:
	server.sendto(data,arr)
	data = f.read(1024)
server.sendto("@#$",arr)
server.close()

