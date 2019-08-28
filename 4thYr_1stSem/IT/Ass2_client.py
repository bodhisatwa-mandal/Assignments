import socket
import threading
import sys
import time
import asyncio
import websockets

class Client:

	def __init__(self, pwd, initial_cmd, host='127.0.0.1', port=12345):

		self.host = host
		self.port = port+pwd
		self.url = 'ws://'+host+':'+self.port

	async def send(mesg):
	    async with websockets.connect(self.url) as websocket:
	        await websocket.send(mesg)

	async def recv():
	    async with websockets.connect(self.url) as websocket:
	        return await websocket.recv()

	def main(self):

		i = 0
		while i < len(self.initial_cmd):
			#print(i, self.initial_cmd[i])
			if self.initial_cmd[i] == 'exit':
				self.send('exit')
				print("Exiting")
				return
			if self.initial_cmd[i] == 'get':
				mesg = self.initial_cmd[i]+" "+self.initial_cmd[i+1]
				self.send(mesg)
				time.sleep(1)
				print("Query sent : "+mesg)
				mesg = self.recv(self.buffer)
				print("Received : ",mesg)
				time.sleep(1)
				i += 2
			elif self.initial_cmd[i] == 'put':
				mesg = self.initial_cmd[i]+" "+self.initial_cmd[i+1]+" "+self.initial_cmd[i+2]
				time.sleep(1)
				self.send(mesg)
				print("Value put successful")
				i+=3

		while True:
			cmd = input().split(" ")
			if cmd[0] == 'exit':
				self.send('exit')
				print("Exiting")
				return
			if cmd[0] == 'get':
				mesg = cmd[0]+" "+cmd[1]
				self.send(mesg)
				time.sleep(1)
				print("Query sent : "+mesg)
				mesg = self.recv(self.buffer)
				print("Received : ",mesg)
				time.sleep(1)
			elif cmd[0] == 'put':
				mesg = cmd[0]+" "+cmd[1]+" "+cmd[2]
				time.sleep(1)
				self.send(mesg)
				print("Value put successful")
	
initial_cmd = sys.argv
pwd, initial_cmd = int(initial_cmd[1]), initial_cmd[2:]
#print(initial_cmd)
client = Client(pwd, initial_cmd)
client.main()