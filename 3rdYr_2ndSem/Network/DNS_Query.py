import socket                   # Import socket module

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)             # Create a socket object
host = "192.168.43.201" #socket.gethostname()
port = 12345
s.connect((host, port))
print("Please input domain name to be connected with:")
d = raw_input()
s.send('1/' + str(d))
server_output = s.recv(1024)
print("IP Address received:")
print(server_output)
s.close()
print('connection closed')