import socket
import sys
import time

server = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
server.bind(('localhost',1234))
print("waiting for client...")
file_name = sys.argv[1]
data,addr = server.recvfrom(1024)

if data == "request" :
	print("sending file name ...")
	server.sendto(file_name,addr)
	ack,addr = server.recvfrom(1024)
	if ack :	
		time.sleep(2)
		f = open(file_name,'rb')
		data = f.read(1024)
		while (data):
			if(server.sendto(data,addr)):
				print("sending file data ...")
				data = f.read(1024)
		server.sendto("@#%",addr)
		f.close()
server.close()