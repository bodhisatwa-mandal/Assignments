import socket
#%%
class Reciever:
    def __init__(self, host=socket.gethostname(), reciever_port=1234):
        self.reciever_client = socket.socket()
        self.reciever_client.connect((host, reciever_port))
        print("Reciever Connected with Channel")
        
        self.frames = ["Hello", "World"]
        self.ack = 0
    
    def send(self):
        while True:
            data = self.reciever_client.recv(1024).decode()
            if data is " " :
                break
            print("Data : ", data)
            self.sender_client.send(str(self.ack).encode())
            self.ack += 1
#%%

host = socket.gethostname()
reciever_port = 1234
reciever_obj = Reciever(host, reciever_port)
#%%
reciever_obj.send()
