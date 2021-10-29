import socket
import sys
import select

client = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
client.connect(('127.0.0.1',8380))

while True:
	socket_list = [sys.stdin,client]


	server_send,user_send,err = select.select(socket_list,[],[])

	for sock in server_send:
		if sock == client:
			msg = client.recv(1024)
			print(msg + "\n")
		else:
			msg = sys.stdin.readline()
			client.send(msg)
			sys.stdout.write("YOU")
			sys.stdout.write(msg)
			sys.stdout.flush()
client.close()

