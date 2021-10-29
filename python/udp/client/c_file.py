import socket

client  = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
msg = raw_input("send 'request' message : ")
client.sendto(msg,('localhost',1234))

file_name,addr = client.recvfrom(1024)
print("Received File : ",file_name.strip())
f = open(file_name.strip(),'wb')
client.sendto("received",addr)
data,addr = client.recvfrom(1024)
while data:
	f.write(data)
	data,addr = client.recvfrom(1024)
	if(data == "@#%") :
		break;
f.close()
client.close()
print("file downloaded")

