import socket
#%%
class Sender:
    def __init__(self, host=socket.gethostname(), sender_port=1234):
        self.sender_client = socket.socket()
        self.sender_client.connect((host, sender_port))