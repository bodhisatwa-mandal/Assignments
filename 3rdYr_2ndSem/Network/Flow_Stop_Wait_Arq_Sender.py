import socket
import time
#%%
class Sender:
    def __init__(self, host=socket.gethostname(), sender_port=1234):
        self.sender_client = socket.socket()
        self.sender_client.connect((host, sender_port))
        self.sender_client.settimeout(2)
        print("Sender Connected with Channel")
        
        self.frames = ["Hello", "World", " "]
    
    def send(self):
        time.sleep(2)
        for frame in self.frames:
            while True:
                if frame != " ":
                    print("Sending Frame : ", frame)
                self.sender_client.send(frame.encode())
                if frame is " ":
                    break
                ack = self.sender_client.recv(1024).decode()
                if len(ack) is not 0:
                    break
            print("Acknowledgement Recieved : ", ack)
#%%

host = socket.gethostname()
sender_port = 1234
sender_obj = Sender(host, sender_port)
#%%
sender_obj.send()