import sys
import socket
#%%
class Channel:
    def __init__(self, num_nodes=4, host=socket.gethostname(), port=1234):
        self.num_nodes = num_nodes
        self.buffer = []
        self.data_list = []
        self.state_list = []
        self.data_address_list = []
        self.state_address_list = []

        data_socket =  socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        data_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        data_socket.bind((host, port))
        data_socket.listen(num_nodes)

        state_socket =  socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        state_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        state_socket.bind((host, port+1))
        state_socket.listen(num_nodes)

        while node_index in range(num_nodes):
            node, node_address = data_socket.accept()
            self.data_list.append(node)
            self.data_address_list.append(node_address)
            print("Node Data Connection", node_index, " Established from : ", self.reciever_address)
            node, node_address = state_socket.accept()
            self.state_list.append(node)
            self.state_address_list.append(node_address)
            print("Node State Connection", node_index, " Established from : ", self.reciever_address)


