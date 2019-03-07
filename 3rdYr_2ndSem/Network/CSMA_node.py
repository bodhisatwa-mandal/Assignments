import sys
import time
import random
import threading
import socket
import re
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
        self.p = 1.0/num_nodes
        self.k = 0
        self.delay = 0

    def sendData(self):
        while True:
            if self.can_send == True:
                if random.random() <= self.p:
                    self.delay-=time.time()
                    for frame in self.frames:
                        time.sleep(random.random())
                        print("Sending Frame : ",frame)
               	        self.data_send_socket.send((str(self.node_id)+frame).encode())
                    return
               	# Value does not satisfy p value
                else:
                    self.k += 1
                    waiting_time = random.random()*self.k#(2**self.k - 1)
                    if waiting_time>1:
                        waiting_time=1
                    print("Waiting for :", waiting_time)
                    time.sleep(waiting_time)
            # Channel is Busy
            else:
                self.k += 1
                waiting_time = random.random()*self.k#(2**self.k - 1)
                if waiting_time > 1:
                    waiting_time=1
                print("Waiting for :", waiting_time)
                time.sleep(waiting_time)

    def recieveData(self):
        while True:
            try:
                string = ''
                data = self.data_recieve_socket.recv(1024).decode()
                if data != '':
                    for ch in range(len(data)):
                        if data[ch].isdigit():
                            if ch!=0:
                                print("Received Data : ",string[1:],"from station : ",string[0])
                                if string==str(node_id)+self.frames[-1]:
                                    self.delay += time.time()
                                    print("Throughput : ",(11/self.delay),"characters per second")
                            string = str(data[ch])
                        else:
                            string = string+str(data[ch])
                    print("Received Data : ",string[1:],"from station : ",string[0])
                    if string==str(node_id)+self.frames[-1]:
                        self.delay += time.time()
                        print("Throughput : ",(11/self.delay),"characters per second")
            except Exception as e:
                print(e)
                pass


    def getChannelInfo(self):
        while True:
            state = self.state_socket.recv(1024).decode()
            if state!='' and (state[0] == "I"):# or int(state[0])==self.node_id):
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
        thread_1.join()
        thread_2.join()
        thread_3.join()
#%%
node_id = int(sys.argv[1])
num_nodes = int(sys.argv[2])
node_obj = Node(node_id=node_id, num_nodes=num_nodes)
#%%
node_obj.drive()



    	
