import socket

server = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
server.bind(('127.0.0.1',1234))

print("waiting for client")
data,addr = server.recvfrom(1024)
print(data)
while True:
	send_data = raw_input("Server :")
	server.sendto(bytes(send_data),addr)
	data,addr = server.recvfrom(1024)
	if data == "OVER":
		server.close()
		break
	print(data)
