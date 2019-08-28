import socket
import threading
import time
import asyncio
import websockets

class Server:
	
	def __init__(self, num_clients, host='127.0.0.1', port=12345):
	
		self.client_dict_list = []
		self.client_state_list = []
		self.url = 'ws://'+host+':'
		self.num_clients = num_clients
		self.main_dict = {}

	def listen(self):

		for i in range(self.num_clients):
			#print("lol")
			self.client_dict_list.append({})
			self.client_state_list.append(0)

		asyncio.get_event_loop().run_until_complete(
					websockets.serve(self.receive, '127.0.0.1', 12345))
		asyncio.get_event_loop().run_forever()

	async def receive(self, websocket, path):
		self.main_dict[(websocket, path)] = len(self.main_dict)
		#print(self.main_dict)
		async for mesg in websocket:
		
			#mesg = await websocket.recv()
			#time.sleep(1)
			client_id = self.main_dict[(websocket, path)]

			mesg = mesg.split(" ")
			if mesg[0] == 'put':
				self.client_dict_list[client_id][mesg[1]] = mesg[2]
			elif mesg[0] == 'get':
				result = '<blank>'
				if self.client_state_list[client_id] == 0:
					if mesg[1] in self.client_dict_list[client_id]:
						result = self.client_dict_list[client_id][mesg[1]]
				elif self.client_state_list[client_id] == 1:
					for j in range(self.num_clients):
						if True or self.client_state_list[j] != 2:
							#print(self.client_dict_list[j])
							if mesg[1] in self.client_dict_list[j]:
								result = self.client_dict_list[j][mesg[1]]
				#async with websockets.connect(self.url+) as websocket:
	        	#	await websocket.send(mesg)
				
				await websocket.send(result)
				#time.sleep(1)
			elif mesg[0] == 'exit':
				self.client_state_list[client_id] = 2
				return

	def promote(self):
		while True:
			print("Enter client id to promote to manager")
			a = int(input())
			if a == -1:
				break
			if a<len(self.client_state_list) and self.client_state_list[a] == 0:
				self.client_state_list[a]=1
				print("Done")

	def main(self):
		#thread_list = []
		#for i in range(self.num_clients):
		thread = threading.Thread(target = self.promote, args=())
		thread.start()
			#thread_list.append(thread)
		self.listen()
		
		thread.join()
server = Server(num_clients=4)
server.main()