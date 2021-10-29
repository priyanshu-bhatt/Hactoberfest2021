import socket
import time
client = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
data = "coonect me"
client.sendto(data,('localhost',10050))
chek_frame = []
len_of_wi,arr = client.recvfrom(1024)
len_of_w = int(float(len_of_wi))
print("length of w : ",len_of_w)

def chek_frames():
	numeric = 0
	for i in chek_frame:
		if int(i) != numeric:
			return numeric
		numeric += 1
		if int(i) == len_of_w:
			del chek_frame[:]
			return "not"
	return "no ack"


def recv_from():
	while True:
		num,arr = client.recvfrom(50);
		if num == "EOF":
			break
		chek_frame.append(num)
		data,arr = client.recvfrom(50);
		print(data + "\n")
		error_frame = chek_frames()
		if(error_frame != "no ack"):
			client.sendto(str(error_frame),arr)
		print("error ",error_frame)
		time.sleep(1)

recv_from()
print(chek_frame)