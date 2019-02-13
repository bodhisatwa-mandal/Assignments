import socket
#%%
class Reciever:
    def __init__(self, host=socket.gethostname(), reciever_port=1234):
        self.reciever_client = socket.socket()
        self.reciever_client.connect((host, reciever_port))
        self.frame_id = 0
        print("Reciever Connected with Channel")
    
    def recieve(self):
        while True:
            data = self.reciever_client.recv(1024).decode()
            if data is " " :
                break
            if int(data)<self.frame_id:
                self.frame_id = int(data)
            print("Data : ", data)
            if int(data) is self.frame_id:
                print("Sending Acknowledgement : ",self.frame_id)
                ack = str(self.frame_id)
                if len(ack) == 1:
                    ack = "0"+ack
                self.reciever_client.send(ack.encode())
                self.frame_id += 1
            elif int(data) is self.frame_id-1:
                print("Sending Acknowledgement : ",self.frame_id-1)      
                self.reciever_client.send(str(self.frame_id-1).encode())
#%%

host = socket.gethostname()
reciever_port = 1235
reciever_obj = Reciever(host, reciever_port)
#%%
reciever_obj.recieve()
