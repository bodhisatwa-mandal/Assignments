import socket
#%%
class Sender:
    def __init__(self, host=socket.gethostname(), sender_port=1234):
        self.sender_client = socket.socket()
        self.sender_client.connect((host, sender_port))
        print("Sender Connected with Channel")
        
        self.frames = ["Hello", "World"]
    
    def send(self):
        for frame in self.frames:
            self.sender_client.send(frame.encode())
            ack = self.sender_client.recv(1024).decode()
            print(ack)