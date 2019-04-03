import socket               # Import socket module
filename = str(input())
s = socket.socket()         # Create a socket object
host = socket.gethostname() # Get local machine name
port = 12345                 # Reserve a port for your service.
s.bind((host, port))        # Bind to the port
f = open(filename,'wb')
s.listen(5)                 # Now wait for client connection.

c, addr = s.accept()     # Establish connection with client.
print('Got connection from', addr)
print("Start Receiving")
l = c.recv(1024)
while (l):
    print("Receiving")
    f.write(l)
    l = c.recv(1024)
f.close()
print("Done Receiving")
#c.send('Thank you for connecting')
c.close()                # Close the connection
