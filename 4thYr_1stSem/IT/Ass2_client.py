import socket
import threading
import sys
import time
import asyncio
import websockets

class Client:

	def __init__(self, initial_cmd, host='127.0.0.1', port=12345):

		#self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
		#self.sock.connect((host, port))
		self.initial_cmd = initial_cmd

		#self.buffer = 1024

	async def get_message(websocket, path):
		async for message in websocket:
			return message

	async def send_message(uri, message):
		async with websockets.connect(uri) as websocket:
			await websocket.send(message)

	def main(self):

		i = 0
		while i < len(self.initial_cmd):
			#print(i, self.initial_cmd[i])
			if self.initial_cmd[i] == 'exit':
				#self.sock.send('exit'.encode())
				asyncio.get_event_loop().run_until_complete(self.send_message('ws://'+self.host+':'+self.port+'12345', 'exit'))
				print("Exiting")
				return
			if self.initial_cmd[i] == 'get':
				mesg = self.initial_cmd[i]+" "+self.initial_cmd[i+1]
				#self.sock.send(mesg.encode())
				asyncio.get_event_loop().run_until_complete(self.send_message('ws://'+self.host+':'+self.port+'12345', mesg))
				time.sleep(1)
				print("Query sent : "+mesg)
				#mesg = self.sock.recv(self.buffer).decode()
				mesg = asyncio.get_event_loop().run_until_complete(websockets.serve(self.get_message, self.host, self.port))
				print("Received : ",mesg)
				time.sleep(1)
				i += 2
			elif self.initial_cmd[i] == 'put':
				mesg = self.initial_cmd[i]+" "+self.initial_cmd[i+1]+" "+self.initial_cmd[i+2]
				time.sleep(1)
				#self.sock.send(mesg.encode())
				asyncio.get_event_loop().run_until_complete(self.send_message('ws://'+self.host+':'+self.port+'12345', mesg))
				print("Value put successful")
				i+=3

		while True:
			cmd = input().split(" ")
			if cmd[0] == 'exit':
				#self.sock.send('exit'.encode())
				asyncio.get_event_loop().run_until_complete(self.send_message('ws://'+self.host+':'+self.port+'12345', 'exit'))
				print("Exiting")
				return
			if cmd[0] == 'get':
				mesg = cmd[0]+" "+cmd[1]
				#self.sock.send(mesg.encode())
				asyncio.get_event_loop().run_until_complete(self.send_message('ws://'+self.host+':'+self.port+'12345', mesg))
				time.sleep(1)
				print("Query sent : "+mesg)
				#mesg = self.sock.recv(self.buffer).decode()
				mesg = asyncio.get_event_loop().run_until_complete(websockets.serve(self.get_message, self.host, self.port))
				print("Received : ",mesg)
				time.sleep(1)
			elif cmd[0] == 'put':
				mesg = cmd[0]+" "+cmd[1]+" "+cmd[2]
				time.sleep(1)
				#self.sock.send(mesg.encode())
				asyncio.get_event_loop().run_until_complete(self.send_message('ws://'+self.host+':'+self.port+'12345', result))
				print("Value put successful")
	
initial_cmd = sys.argv
initial_cmd = initial_cmd[1:]
#print(initial_cmd)
client = Client(initial_cmd)
client.main()