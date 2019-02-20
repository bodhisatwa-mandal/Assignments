import socket
#%%
class Reciever:
    def __init__(self, host=socket.gethostname(), reciever_port=1234, frame_len=4):
        self.reciever_client = socket.socket()
        self.reciever_client.connect((host, reciever_port))
        self.frame_id = 0
        self.frame_len = frame_len
        self.recieve_window = [False]*frame_len
        print("Reciever Connected with Channel")
    
    def recieve(self):
        while True:
            data = self.reciever_client.recv(1024).decode()
            if data is " " :
                break
            if int(data)>=self.frame_id:
                recieved_id = int(data)
                self.recieve_window[recieved_id%self.frame_len] = True
                print("Data : ", data)
                print("Sending Acknowledgement : ",self.frame_id)
                self.reciever_client.send(data.encode())
                if not False in self.recieve_window:
                    self.recieve_window = [False]*frame_len
                    self.frame_id += self.frame_len
            elif int(data) < self.frame_id:
                print("Sending Acknowledgement : ",data)
                self.reciever_client.send(data.encode())
#%%

host = socket.gethostname()
reciever_port = 1235
frame_len = 4
reciever_obj = Reciever(host, reciever_port, frame_len)
#%%
reciever_obj.recieve()
