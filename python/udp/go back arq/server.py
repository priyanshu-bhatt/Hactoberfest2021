import socket
import math
import time

server = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
server.bind(('localhost',10050))
data,arr = server.recvfrom(1024)
print("connected to :" ,arr)
def take_input():
	global msg 
	msg = raw_input("Enter message to send")
	lenght_of_window = math.pow(2,2) - 1
	server.sendto(str(lenght_of_window),arr)
	return lenght_of_window

def send_data(length_of_w):
	seq_no = 0;
	for i in range(len(msg)):
		server.sendto(str(seq_no),arr)
		server.sendto(msg[i],arr)
		if(seq_no == length_of_w):
			err,arr1 = server.recvfrom(1024)
			if err != "not":
				i = i- (seq_no - int(err))
				print("value of i ",i)
			seq_no = 0
			time.sleep(2)
		seq_no += 1
	server.sendto("EOF",arr)

lk = take_input()
print(msg + " " + str(lk))
send_data(lk)
