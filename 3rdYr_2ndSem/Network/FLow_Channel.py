import random
import socket
import threading
import time
#%%

host=socket.gethostname()
sender_port=1234
reciever_port=1235
max_delay = 3

#%%
class Channel:
    def __init__(self, host=socket.gethostname(), sender_port=1234, reciever_port=1235):
        
        # Initialize Reciever Socket
        self.reciever_socket =  socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.reciever_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self.reciever_socket.bind((host, reciever_port))
        self.reciever_socket.listen(10)
        self.reciever, self.reciever_address = self.reciever_socket.accept()
        print("Reciever Connection Established from : ", self.reciever_address)
        
        # Initialize Sender Socket
        self.sender_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.sender_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self.sender_socket.bind((host, sender_port))
        self.sender_socket.listen(10)
        self.sender, self.sender_address = self.sender_socket.accept()
        print("Sender Connection Established from : ", self.sender_address)
        
        # Initialize Buffers
        self.data_buffer = []
        self.ack_buffer = []
        
    def sender_to_buffer(self):
        while True:
            data = self.sender.recv(1024)
            string = data.decode()
            if string != " " and len(self.data_buffer)>0 and int(self.data_buffer[-1]) > int(string[0:2]):
                self.data_buffer=list(map(''.join, zip(*[iter(string)]*2)))
            else:
                self.data_buffer+=list(map(''.join, zip(*[iter(string)]*2)))
            if len(string)!=0 and string[-1] == " ":
                self.data_buffer.append(" ")
            print('data',self.data_buffer)
    
    def buffer_to_reciever(self):
        while True:
            if len(self.data_buffer) != 0:
                time.sleep(int(random.random()*max_delay))
                to_send = self.data_buffer.pop(0)
                self.reciever.send(to_send.encode())
        
    def reciever_to_buffer(self):
        while True:
            ack = self.reciever.recv(1024)
            string = ack.decode()
            if len(self.ack_buffer)>0 and len(string)>0 and int(self.ack_buffer[-1]) > int(string[0:2]):
                self.ack_buffer=list(map(''.join, zip(*[iter(string)]*2)))
            else:
                self.ack_buffer+=list(map(''.join, zip(*[iter(string)]*2)))
            print('ack',self.ack_buffer)

    def buffer_to_sender(self):
        while True:
            if len(self.ack_buffer) != 0:
                time.sleep(int(random.random()*max_delay))
                to_send = self.ack_buffer.pop(0)
                self.sender.send(to_send.encode())
        
    
    def start_channel(self):
        thread_1 = threading.Thread(target=self.sender_to_buffer, args=())
        thread_2 = threading.Thread(target=self.reciever_to_buffer, args=())
        thread_3 = threading.Thread(target=self.buffer_to_reciever, args=())
        thread_4 = threading.Thread(target=self.buffer_to_sender, args=())
        thread_1.start()
        thread_2.start()
        thread_3.start()
        thread_4.start()
    
#%%
channel_obj = Channel(host, sender_port, reciever_port)
#%%
channel_obj.start_channel()
