import socket
import time
import threading

#%%
class Sender:
    def __init__(self, host=socket.gethostname(), sender_port=1234):
        self.sender_client = socket.socket()
        self.sender_client.connect((host, sender_port))
        self.sender_client.settimeout(2)
        self.timer_threshold =3
        print("Sender Connected with Channel")
        self.data_id = 0
        self.ack_id = 0
        self.sent_time = 0
        self.frames = ["00", "01", " "]
        
    def recieve(self):
        while True:
            if self.ack_id is len(self.frames)-1:
                break
            try:
                ack = self.sender_client.recv(1024).decode()
                print("Acknowledgement Recieved : ", ack)
            except:
                ack = None
            if ack is None:
                continue
            if int(ack) == self.ack_id:
                self.ack_id += 1
                print(self.ack_id)
                
    def send(self):
        while True:
            if self.data_id == self.ack_id:
                if not (self.frames[self.data_id] == " "):
                    print("Sending Frame : ",self.frames[self.data_id])
                self.sender_client.send(self.frames[self.data_id].encode())
                self.sent_time = time.time()
                if self.frames[self.data_id] is " ":
                    return
                self.data_id += 1
            if self.ack_id == len(self.frames)-1:
                break
            elif time.time()-self.sent_time > self.timer_threshold:
                print("Sending Frame : ",self.frames[self.data_id-1])
                self.sender_client.send(self.frames[self.data_id-1].encode())
                self.sent_time = time.time()

    def drive(self):
        thread_1 = threading.Thread(target=self.send, args=())
        thread_2 = threading.Thread(target=self.recieve, args=())
        thread_2.start()
        thread_1.start()
        thread_2.join()
        thread_1.join()
#%%

host = socket.gethostname()
sender_port = 1234
sender_obj = Sender(host, sender_port)
#%%
sender_obj.drive()