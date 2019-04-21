import socket                   # Import socket module

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)             # Create a socket object
host = "192.168.43.201" #socket.gethostname()
port = 12345
s.connect((host, port))
print("Please input domain name:")
d = raw_input()
s.send(str(d))
s.close()
print('connection closed')