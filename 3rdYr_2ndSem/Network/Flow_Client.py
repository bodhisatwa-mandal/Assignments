import socket
import time
#%%

ip = "127.0.0.1"
port = 1234

client_socket = socket.socket()
client_socket.bind((ip, port))

#%%

#time.sleep(1)
client_socket.listen(10)
client, address = client_socket.accept()
#%%
client.send("Hello World".encode())
#%%
client_socket.close()