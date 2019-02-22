import sys
import socket
#%%
class Channel:
    def __init__(self, num_nodes=4, host=socket.gethostname(), port=1234):
        self.num_nodes = num_nodes
        self.buffer = []
        self.node_list = []
        self.node_address_list = []

        node_socket =  socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        node_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        node_socket.bind((host, port))
        node_socket.listen(num_nodes)

        while node_index in range(num_nodes):
            node, node_address = node_socket.accept()
            node_list.append(node)
            node_address_list.append(node_address)
            print("Reciever Connection", node_index, " Established from : ", self.reciever_address)