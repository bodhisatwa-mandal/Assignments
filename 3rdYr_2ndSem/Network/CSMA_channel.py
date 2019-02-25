import sys
import socket
import threading
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
        self.from_node_socket.settimeout(2)
        self.from_node_socket.listen(num_nodes)

        self.to_node_socket =  socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.to_node_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self.to_node_socket.bind((host, 1235))
        self.from_node_socket.listen(num_nodes)

        self.state_socket =  socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.state_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self.state_socket.bind((host, 1236))
        self.from_node_socket.listen(num_nodes)

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

    def channelStatus(self):
        if len(self.buffer)>0:
            for state in self.state_list:
                self.state.send("Idle".encode())
        else:
            for state in self.state_list:
                self.state.send(buffer[0][0].encode())

    def node_to_buffer(self):
        for node in self.from_node_list:
            try:
                data = node.recv(1024)
                string = data.decode()
                self.buffer.append(string)
            except:
                pass
        self.channelStatus()

    def buffer_to_node(self):
        buff_size = len(buffer)
        for i in range(buff_size):
            for node in self.to_node_list:
                self.node.send(self.buffer[0].encode())
            del self.buffer[0]
        self.channelStatus()

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




