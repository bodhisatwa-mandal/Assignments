import socket
import threading
import sys
import time

class Client:

	def __init__(self, initial_cmd, host='127.0.0.1', port=12345):

		self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
		self.sock.connect((host, port))
		self.initial_cmd = initial_cmd

		self.buffer = 1024

	def main(self):

		i = 0
		while i < len(self.initial_cmd):
			#print(i, self.initial_cmd[i])
			if self.initial_cmd[i] == 'exit':
				self.sock.send('exit'.encode())
				print("Exiting")
				return
			if self.initial_cmd[i] == 'get':
				mesg = self.initial_cmd[i]+" "+self.initial_cmd[i+1]
				self.sock.send(mesg.encode())
				time.sleep(1)
				print("Query sent : "+mesg)
				mesg = self.sock.recv(self.buffer).decode()
				print("Received : ",mesg)
				time.sleep(1)
				i += 2
			elif self.initial_cmd[i] == 'put':
				mesg = self.initial_cmd[i]+" "+self.initial_cmd[i+1]+" "+self.initial_cmd[i+2]
				time.sleep(1)
				self.sock.send(mesg.encode())
				print("Value put successful")
				i+=3

		while True:
			cmd = input().split(" ")
			if cmd[0] == 'exit':
				self.sock.send('exit'.encode())
				print("Exiting")
				return
			if cmd[0] == 'get':
				mesg = cmd[0]+" "+cmd[1]
				self.sock.send(mesg.encode())
				time.sleep(1)
				print("Query sent : "+mesg)
				mesg = self.sock.recv(self.buffer).decode()
				print("Received : ",mesg)
				time.sleep(1)
			elif cmd[0] == 'put':
				mesg = cmd[0]+" "+cmd[1]+" "+cmd[2]
				time.sleep(1)
				self.sock.send(mesg.encode())
				print("Value put successful")
	
initial_cmd = sys.argv
initial_cmd = initial_cmd[1:]
#print(initial_cmd)
client = Client(initial_cmd)
client.main()