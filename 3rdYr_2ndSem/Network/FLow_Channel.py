import random
import socket
import threading
import time
#%%

host=socket.gethostname()
sender_port=1234
reciever_port=1235
max_delay = 4

#%%
class Channel:
    def __init__(self, host=socket.gethostname(), sender_port=1234, reciever_port=1235):
        
        # Initialize Reciever Socket
        self.reciever_socket =  socket.socket()
        self.reciever_socket.bind((host, reciever_port))
        self.reciever_socket.listen(10)
        self.reciever, self.reciever_address = self.reciever_socket.accept()
        print("Reciever Connection Established from : ", self.reciever_address)
        
        # Initialize Sender Socket
        self.sender_socket = socket.socket()
        self.sender_socket.bind((host, sender_port))
        self.sender_socket.listen(10)
        self.sender, self.sender_address = self.sender_socket.accept()
        print("Sender Connection Established from : ", self.sender_address)
        
        # Initialize Buffers
        self.data_buffer = []
        self.ack_buffer = []
        
    def sender_to_reciever(self):
        while True:
            data = self.sender.recv(1024)
            time.sleep(int(random.random()*max_delay))
            self.reciever.send(data)
        
    def reciever_to_sender(self):
        while True:
            ack = self.reciever.recv(1024)
            time.sleep(int(random.random()*max_delay))
            self.sender.send(ack)
    
    def start_channel(self):
        thread_1 = threading.Thread(target=self.sender_to_reciever, args=())
        thread_2 = threading.Thread(target=self.reciever_to_sender, args=())
        thread_1.start()
        thread_2.start()
    
#%%
channel_obj = Channel(host, sender_port, reciever_port)
#%%
channel_obj.start_channel()
