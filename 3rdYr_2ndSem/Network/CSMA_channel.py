import sys
import socket
import threading
import time
import random
#import asyncio
#%%
class Channel:
    def __init__(self, num_nodes=4, host=socket.gethostname()):
        self.num_nodes = num_nodes
        self.buffer = []

        self.from_node_list = []
        self.to_node_list = []
        self.state_list = []
        self.from_node_address_list = []
        self.to_node_address_list = []
        self.state_address_list = []

        self.from_node_socket =  socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.from_node_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self.from_node_socket.bind((host, 1234))
        #self.from_node_socket.settimeout(2)
        self.from_node_socket.listen(num_nodes)

        self.to_node_socket =  socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.to_node_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self.to_node_socket.bind((host, 1235))
        self.to_node_socket.listen(num_nodes)

        self.state_socket =  socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.state_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self.state_socket.bind((host, 1236))
        self.state_socket.listen(num_nodes)

        for node_index in range(num_nodes):

            node, node_address = self.from_node_socket.accept()
            self.from_node_list.append(node)
            self.from_node_address_list.append(node_address)
            print("Recieve Connection", node_index, " Established from : ", node_address)

            node, node_address = self.to_node_socket.accept()
            self.to_node_list.append(node)
            self.to_node_address_list.append(node_address)
            print("Send Connection", node_index, " Established from : ", node_address)

            node, node_address = self.state_socket.accept()
            self.state_list.append(node)
            self.state_address_list.append(node_address)
            print("State Connection", node_index, " Established from : ", node_address)

        self.sem0 = threading.Semaphore()
        self.sem1 = threading.Semaphore()

    def channelStatus(self):
        while(True):
            try:
                if len(self.buffer)==0:
                    for state in self.state_list:
                        state.send("Idle".encode())
                else:
                    for state in self.state_list:
                        state.send(self.buffer[0][0].encode())
            except:
                pass

    def node_to_buffer_helper(self, node):
        try:
            data = node.recv(1024)
            string = data.decode()
            if string!='':
                print('Received Data : ',string)
            self.sem0.acquire()
            self.buffer += [string]
            self.sem0.release()
        except:
            pass

    def node_to_buffer(self):
        while True:
            thread_list = []
            for node in self.from_node_list:
                temp_thread = threading.Thread(target=self.node_to_buffer_helper,args=([node]))
                temp_thread.start()
                thread_list.append(temp_thread)
            for temp_thread in thread_list:
                temp_thread.join()



            #self.channelStatus()

    def buffer_to_node(self):
        while True:
            buff_size = len(self.buffer)
            for i in range(buff_size):
                try:
                    if len(self.buffer)!=0 :# and self.buffer[-1][-1]=='#':
                        node_id=0
                        for node in self.to_node_list:
                            time.sleep(random.random())
                            node.send(self.buffer[0].encode())
                            if self.buffer[0]!='':
                                print("Sending : ", self.buffer[0], "to station : ", node_id)
                            node_id += 1
                        self.sem1.acquire()
                        del self.buffer[0]
                        self.sem1.release()
                    #elif len(self.buffer)!=0:
                        #print(self.buffer)
                except:
                    i-=1
                #    print("Error")
                #    i-=1
            #self.channelStatus()

    def start_channel(self):
        thread_1 = threading.Thread(target=self.channelStatus, args=())
        thread_2 = threading.Thread(target=self.node_to_buffer, args=())
        thread_3 = threading.Thread(target=self.buffer_to_node, args=())
        thread_1.start()
        thread_2.start()
        thread_3.start()
        thread_1.join()
        thread_2.join()
        thread_3.join()
#%%
num_nodes = int(sys.argv[1])
channel_obj = Channel(num_nodes = num_nodes)
#%%
channel_obj.start_channel()




