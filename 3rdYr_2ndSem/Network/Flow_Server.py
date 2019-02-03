import socket
import time
#%%

ip = "127.0.0.1"
port = 1234

server_socket = socket.socket()

#%%

server_socket.connect((ip, port))
print(server_socket.recv(1024).decode())

#%%
server_socket.close()