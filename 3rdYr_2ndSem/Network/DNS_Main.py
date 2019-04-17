from __future__ import division
import socket
import sys
buffer_size = 1024

def main():
    start_server()


def start_server():
    host = socket.gethostname()
    port = 1200        # arbitrary non-privileged port

    soc = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    soc.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)   # SO_REUSEADDR flag tells the kernel to reuse a local socket in TIME_WAIT state, without waiting for its natural timeout to expire
    print("Socket created")
    domain_list = []
    domain = {}

    try:
        soc.bind((host, port))
    except:
        print("Bind failed. Error : " + str(sys.exc_info()))
        sys.exit()

    print("Socket now listening")
    num = True
    while(num):
        data, address1 = soc.recvfrom(1024)
        if(str(data.split("/")[0]) == '1'):
            query = str(data[2:])
            print("User query for: ")
            print(query)
            if query in domain:
                soc.sendto(domain[query], address1)
            else:
                soc.sendto("404", address1)
        else:
            domain_name = str(data)
            ip1, port1 = str(address1[0]), str(address1[1])
            print("Trying to register domain name")
            if(domain_name not in domain_list):
                domain_list.append(domain_name)
                domain[domain_name] = ip1 + ':' + port1
                print("Domain name registration successful")
                print(domain_name + ' == [' + domain[domain_name] + ']')
            else:
                print("Domain name registration failed. Domain name already exist.")


    soc.close()

def receive_input(connection, max_buffer_size):
    client_input = connection.recv(max_buffer_size)
    client_input_size = sys.getsizeof(client_input)

    if client_input_size > max_buffer_size:
        print("The input size is greater than expected {}".format(client_input_size))

    decoded_input = client_input.decode("utf8").rstrip()  # decode and strip end of line
    result = process_input(decoded_input)

    return result

def process_input(input_str):
    return str(input_str).upper()

if __name__ == "__main__":
    main()
