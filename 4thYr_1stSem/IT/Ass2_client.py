import socket
import threading
import sys
import time
import asyncio
import websockets

class Client:

	def __init__(self, initial_cmd, host='127.0.0.1', port=12345):

		self.host = host
		self.port = port
		self.url = 'ws://'+host+':'+str(self.port)
		self.initial_cmd = initial_cmd


	async def main(self):
		async with websockets.connect(self.url) as websocket:
			i = 0
			while i < len(self.initial_cmd):
				#print(i, self.initial_cmd[i])
				if self.initial_cmd[i] == 'exit':
					await websocket.send('exit')
					print("Exiting")
					return
				if self.initial_cmd[i] == 'get':
					mesg = self.initial_cmd[i]+" "+self.initial_cmd[i+1]
					await websocket.send(mesg)
					#time.sleep(1)
					print("Query sent : "+mesg)
					mesg = await websocket.recv()
					print("Received : ",mesg)
					#time.sleep(1)
					i += 2
				elif self.initial_cmd[i] == 'put':
					mesg = self.initial_cmd[i]+" "+self.initial_cmd[i+1]+" "+self.initial_cmd[i+2]
					#time.sleep(1)
					await websocket.send(mesg)
					print("Value put successful")
					i+=3

			while True:
				cmd = input().split(" ")
				if cmd[0] == 'exit':
					await websocket.send('exit')
					print("Exiting")
					return
				if cmd[0] == 'get':
					mesg = cmd[0]+" "+cmd[1]
					await websocket.send(mesg)
					#time.sleep(1)
					print("Query sent : "+mesg)
					mesg = await websocket.recv()
					print("Received : ",mesg)
					#time.sleep(1)
				elif cmd[0] == 'put':
					mesg = cmd[0]+" "+cmd[1]+" "+cmd[2]
					#time.sleep(1)
					print(mesg)
					await websocket.send(mesg)
					print("Value put successful")
	
initial_cmd = sys.argv
initial_cmd = initial_cmd[1:]
#print(initial_cmd)
client = Client(initial_cmd)
#client.main()
asyncio.get_event_loop().run_until_complete(
						client.main())