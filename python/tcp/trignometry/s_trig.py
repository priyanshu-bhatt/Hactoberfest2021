import socket
import math

server = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
server.bind(('localhost',6363))
server.listen(10)
conn,addr = server.accept()

print("Connected to :" ,addr)

def result(opt,angle1):
	angle = float(angle1)
	if opt == "1":
		return math.sin(angle)
	if opt == "2":
		return math.cos(angle)
	if opt == "3":
		return math.tan(angle)

while True:
	oper = conn.recv(1024)
	ang = conn.recv(1024)
	print(oper + ang)
	ans = result(oper,ang)
	conn.send(str(ans))

