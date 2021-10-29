import socket

client = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

send_data = raw_input("client :")
client.sendto(bytes(send_data),('127.0.0.1',1234))
while True:
	data,addr = client.recvfrom(1024)
	print(data)
	if data == "OVER":
		client.close()
		break
	send_data = raw_input("client :")
	client.sendto(bytes(send_data),('127.0.0.1',1234))
	if send_data == "OVER" :
		client.close()
		break