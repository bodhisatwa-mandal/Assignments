import socket
import threading
import time
import asyncio
import websockets

class Server:
	
	def __init__(self, num_clients, host='127.0.0.1', port=12345):
	
		self.client_dict_list = []
		self.client_state_list = []

		self.num_clients = num_clients


	def listen(self):

		for i in range(self.num_clients):
			self.client_dict_list.append({})
			self.client_state_list.append(0)
			asyncio.get_event_loop().run_until_complete(
					websockets.serve(self.receive, 'localhost', 12345+i))
			asyncio.get_event_loop().run_forever()

	async def receive(self, websocket, path):
		print(websocket.port)
		client_id = websocket.port-12345
		async for message in websocket:
			mesg = await websocket.recv()
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
				await websocket.send(result)
				time.sleep(1)
			elif mesg[0] == 'exit':
				self.client_state_list[client_id] = 2
				return

	def main(self):

		self.listen()
		while True:
			print("Enter client id to promote to manager")
			a = int(input())
			if a == -1:
				break
			if a<len(self.client_state_list) and self.client_state_list[a] == 0:
				self.client_state_list[a]=1
				print("Done")

server = Server(num_clients=10)
server.main()