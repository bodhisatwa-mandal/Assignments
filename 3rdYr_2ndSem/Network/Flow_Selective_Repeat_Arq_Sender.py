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

        self.sent_time = [0]*frame_len
        self.sender_window = [False]*frame_len
        self.ack_id = 0

        self.frames = ["00", "01", "02", "03", "04", "05", " "]
        
    def recieve(self):
        while True:
            if self.ack_id == len(self.frames)-1:
                break
            try:
                ack = self.sender_client.recv(1024).decode()
                print("Acknowledgement Recieved : ", ack)
            except:
                ack = None
            if ack is None:
                continue
            if int(ack) >= self.ack_id:
                recieved_id = int(data)
                self.sender_window[recieved_id%self.frame_len] = True
                self.sent_timer[recieved_id%self.frame_len] = -1
                if not False in self.sender_window:
                    self.sender_window = [False]*frame_len
                    self.ack_id += self.frame_len
                    self.sent_timer = [0]*frame_len
                
    def send(self):
        while True:
            if self.ack_id = len(self.frames)-1:
                self.sender_client.send(self.frames[self.ack_id].encode())
                break
            else
                for send_id in range(self.ack_id, self.ack_id+self.frame_len, 1):
                    if self.sent_timer[send_id] == 0:
                        print("Sending Frame : ",self.frames[send_id])
                        self.sender_client.send(self.frames[self.send_id].encode())
                        self.sent_timer[send_id] = time.time()
                    elif self.sent_timer[send_id]!=-1 and (time.time()-self.sent_time[send_id]>self.timer_threshold)
                        print("Resending Frame : ",self.frames[send_id])
                        self.sender_client.send(self.frames[self.send_id].encode())
                        self.sent_timer[send_id] = time.time()

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
frame_len = 3
sender_obj = Sender(host, sender_port, frame_len)
#%%
sender_obj.drive()