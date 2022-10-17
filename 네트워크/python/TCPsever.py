from socket import *

s_ip = 'localhost'
s_port = 12345

s_sock = socket(AF_INET, SOCK_STREAM)

s_sock.bind( (s_ip, s_port) )
s_sock.listen(2)

client, c_addr = s_sock.accept()
print(c_addr, 'is conneted')

data1 = "Thank you for conneting"
client.send(data1.encode('utf-8'))

client.close()
s_sock.close()