import socket                   # Import socket module

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)             # Create a socket object
host = "127.0.0.1"
port = 50000  
s.connect((host, port))
print("Please input domain name:")
d = raw_input()
s.send(str(d))
s.close()
print('connection closed')