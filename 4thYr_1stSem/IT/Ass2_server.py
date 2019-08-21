import socket
import threading
import time
import asyncio
import websockets

class Server:
	
	def __init__(self, num_clients, host='127.0.0.1', port=12345):
	
		#self.serv = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
		#self.serv.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
		#self.serv.bind((host, port))
		#self.serv.listen(num_clients)

		#self.client_list = []
		#self.client_address_list = []
		self.client_dict_list = []
		self.client_state_list = []

		self.max_clients = num_clients
		self.connected_clients = 0

		#self.buffer = 1024
		self.host = host
		self.port = port

	def listen(self):

		while self.connected_clients<self.max_clients:
			#c,addr = self.serv.accept()
			#self.client_list.append(c)
			#self.client_address_list.append(addr)
			self.client_dict_list.append({})
			self.client_state_list.append(0)
			self.connected_clients += 1
			#print("Connected to client ",c,'at address ',addr)
			thread = threading.Thread(target=self.receive, args=(self.connected_clients-1,))
			thread.start()

	async def get_message(websocket, path):
		async for message in websocket:
			return message

	async def send_message(uri, message):
		async with websockets.connect(uri) as websocket:
			await websocket.send(message)

	def receive(self, client_id):

		while True:
			mesg = asyncio.get_event_loop().run_until_complete(websockets.serve(self.get_message, self.host, self.port))
			time.sleep(1)
			mesg = mesg.split(" ")
			#print(mesg)
			if mesg[0] == 'put':
				self.client_dict_list[client_id][mesg[1]] = mesg[2]
			elif mesg[0] == 'get':
				result = '<blank>'
				if self.client_state_list[client_id] == 0:
					if mesg[1] in self.client_dict_list[client_id]:
						result = self.client_dict_list[client_id][mesg[1]]
				elif self.client_state_list[client_id] == 1:
					for j in range(self.connected_clients):
						if True or self.client_state_list[j] != 2:
							#print(self.client_dict_list[j])
							if mesg[1] in self.client_dict_list[j]:
								result = self.client_dict_list[j][mesg[1]]
				asyncio.get_event_loop().run_until_complete(self.send_message('ws://'+self.host+':'+self.port+'12345', result))
				time.sleep(1)
			elif mesg[0] == 'exit':
				self.client_state_list[client_id] = 2
				return

	def main(self):

		thread = threading.Thread(target = self.listen, args=())
		thread.start()
		while True:
			print("Enter client id to promote to manager")
			a = int(input())
			if a == -1:
				break
			if a<len(self.client_state_list) and self.client_state_list[a] == 0:
				self.client_state_list[a]=1
				print("Done")
		#thread.raise_exception()
		thread.join()

server = Server(num_clients=10)
server.main()