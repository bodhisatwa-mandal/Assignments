import socket               # Import socket module

print("Enter file name")
filename = str(input())

s = socket.socket()         # Create a socket object
host = "192.168.43.160" #socket.gethostname() # Get local machine name
port = 12345                 # Reserve a port for your service.

s.connect((host, port))

f = open(filename,'rb')
print('Sending Started')
l = f.read(1024)
while (l):
    print('Sending')
    s.send(l)
    l = f.read(1024)
f.close()
print("Done Sending")
s.shutdown(socket.SHUT_WR)
#s.close()                     # Close the socket when done
