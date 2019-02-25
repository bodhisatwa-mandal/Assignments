import sys
#%%
class Node:
    def __init__(self, node_id, host=socket.gethostname(), port=1234):
        self.node_id = node_id
        
        self.data_send_socket = socket.socket()
        self.data_send_socket.connect((host, port))

        self.data_recieve_socket = socket.socket()
        self.data_send_socket.connect((host, port+1))

        self.state_socket = socket.socket()
        self.state_socket.connect((host, port+2))
        
        print("Node", node_id, "Connected to Channel")
        self.can_send = False

    def getChannelInfo(self):
    	state = self.state_socket.recv(1024).decode()
    	if state == "True":
    		self.can_send = True
    	else:
    		self.can_send = False

    def sendData(self):
    	
