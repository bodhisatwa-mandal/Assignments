import socket
import time
import threading

#%%
class Sender:
    def __init__(self, host=socket.gethostname(), sender_port=1234, frame_len=4):
        self.sender_client = socket.socket()
        self.sender_client.connect((host, sender_port))
        self.sender_client.settimeout(2)
        self.timer_threshold =3
        print("Sender Connected with Channel")

        self.sent_time = []

        self.S_b = 0
        self.S_w = frame_len
        self.S_n = 0

        self.frames = ["00", "01", "02", "03", "04", " "]
        
    def recieve(self):
        while True:
            if self.S_b == len(self.frames)-1:
                break
            try:
                ack = self.sender_client.recv(1024).decode()
                print("Acknowledgement Recieved : ", ack)
            except:
                ack = None
            if ack is None:
                continue
            if int(ack) == self.S_b:
                self.S_b += 1
                
    def send(self):
        while True:
            if self.S_n-self.S_b+1 <= self.S_w:
                if not (self.frames[self.S_n] == " "):
                    print("Sending Frame : ",self.frames[self.S_n])
                self.sender_client.send(self.frames[self.S_n].encode())
                self.sent_time.append(time.time())
                if self.frames[self.S_n] is " ":
                    return
                if self.S_n != len(self.frames):
                    self.S_n += 1
            if self.S_b == len(self.frames)-1:
                break
            if (len(self.sent_time)!=0) and (time.time()-self.sent_time[0]>self.timer_threshold):
                for i in range(self.S_b, self.S_n, 1):
                    del self.sent_time[0]
                    print("Sending Frame : ",self.frames[i])
                    self.sender_client.send(self.frames[i].encode())
                    self.sent_time.append(time.time())

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
frame_len = 4
sender_obj = Sender(host, sender_port, frame_len)
#%%
sender_obj.drive()