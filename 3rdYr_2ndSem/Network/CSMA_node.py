import sys
import time
import random
import threading
import socket
#%%
class Node:
    def __init__(self, node_id, num_nodes, host=socket.gethostname()):
        self.node_id = node_id
        
        self.data_send_socket = socket.socket()
        self.data_send_socket.connect((host, 1234))
        
        self.data_recieve_socket = socket.socket()
        self.data_recieve_socket.connect((host, 1235))

        self.state_socket = socket.socket()
        self.state_socket.connect((host, 1236))
        
        print("Node", node_id, "Connected to Channel")
        self.can_send = False

        self.frames = ['Hello', 'World', '#']
        self.p = 0.15

        self.wait_time = random.random()
        self.increment_waitimg_time = random.random()

    def sendData(self):
        while True:
            if self.can_send == True:
                if random.random() <= self.p:
                    for frame in self.frames:
                        print("Sending Frame : ",frame)
               	        self.data_send_socket.send((str(self.node_id)+frame).encode())
                    return
               	# Value does not satisfy p value
                else:
                    print("Waiting for :",self.wait_time)
                    time.sleep(self.wait_time)
                    self.wait_time += self.wait_time*self.increment_waitimg_time
                    if self.wait_time > 0.5:
                        self.wait_time = 0.5
                    #self.can_send = False
            # Channel is Busy
            else:
                print("Waiting for :",self.wait_time)
                time.sleep(self.wait_time)
                self.wait_time += self.wait_time*self.increment_waitimg_time
                if self.wait_time > 0.5:
                    self.wait_time = 0.5
                #self.can_send = False

    def recieveData(self):
        while True:
            try:
                data = self.data_recieve_socket.recv(1024).decode()
                if data != '':
                    print("Data Recieved : ", data)
            except:
                pass


    def getChannelInfo(self):
        while True:
            state = self.state_socket.recv(1024).decode()
            if state!='' and (state[0] == "I" or int(state[0])==self.node_id):
                #if state[0]!='I':
                #    print(state[0])
                self.can_send = True
            else:
                self.can_send = False

    def drive(self):
        thread_1 = threading.Thread(target=self.getChannelInfo, args=())
        thread_2 = threading.Thread(target=self.recieveData, args=())
        thread_3 = threading.Thread(target=self.sendData, args=())
        thread_1.start()
        thread_2.start()
        thread_3.start()
        #thread_1.join()
        #thread_2.join()
        #thread_3.join()
#%%
node_id = int(sys.argv[1])
num_nodes = int(sys.argv[2])
node_obj = Node(node_id=node_id, num_nodes=num_nodes)
#%%
node_obj.drive()



    	
