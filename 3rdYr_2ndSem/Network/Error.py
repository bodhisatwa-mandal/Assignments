
# Name  : Bodhisatwa Mandal
# Roll  : 001610501057
# Class : BCSE-III
# Group : A2 

#%%

import random

#%%

# Sender Class
# Functions :
#               (0) __init__(frame_len)        : Initialize sender
#               (1) read_from_file(path)       : Reads file from given path
#               (2) make_frames(string)        : Make frames of given size
#               (3) calculate_checksum(frames) : Calculate the checksum
#                                                and add checksum frame
#               (4) calculate_LRC(frames)      : Calculate using Longitudinal
#                                                 Redundancy Check
#               (5) calculate_VRC(frames)      : Calculate using Vertical
#                                                 Redundancy Check
#               (6) calculate_CRC(frames)      : Calculate using Cyclic
#                                                 Redundancy Check
#               (7) send(path)                 : Function to send

class Sender:
    
    
    
    # Init function
    def __init__(self, crc_generator):
        self.crc_generator = crc_generator
        
        
        
    # Function to take input from the file in string format
    # Remove newline character from string if present
    # Return the string
    def read_from_file(self, path):
        
        # Open file in read mode
        F = open(path,'r')
        
        # Read from file
        string = F.read()
        
        # Remove newline character if present
        if string[-1] is '\n':
            string = string[:-1]
        
        # Close the file
        F.close()
        
        # Return string
        return string
    
    
    
    # Function to break string into list of frames of given size
    # Convert each frame into integer and return the list
    def make_frames(self, string, num_crc_frames):

        # Get number of redundant bits
        redundant_bits = num_crc_frames*(len(self.crc_generator)-1)
        old_length = 0
        
        # Loop till not padding is needed
        while len(string) is not old_length:
            
            old_length = len(string)
            
            # For Checksum
            frame_len_Checksum = redundant_bits
            # Make length of string divisible by frame length
            while len(string)%frame_len_Checksum is not 0:
                string = '0'+string
            
            # For LRC
            frame_len_LRC = redundant_bits
            # Make length of string divisible by frame length
            while len(string)%frame_len_LRC is not 0:
                string = '0'+string
            
            # For VRC
            num_frames_VRC = redundant_bits
            # Make length of string divisible by number of frames
            while (len(string))%num_frames_VRC is not 0:
                string = '0'+string
            
            # For CRC
            num_frames_CRC = num_crc_frames
            # Make length of string divisible by number of frames
            while (len(string))%num_frames_CRC is not 0:
                string = '0'+string        
        
        frames=[]
        # Store frame lenghts for each detection type
        frame_lengths = [frame_len_Checksum, 
                         frame_len_LRC, 
                         int((len(string)+redundant_bits)/num_frames_VRC)-1, 
                         int((len(string)+redundant_bits)/num_frames_CRC)-len(self.crc_generator)+1]
        
        # Break into frames for each case
        for error_type in range(4):
            index = 0
            frame = []
            # Make frames
            while index is not len(string):
                frame.append(string[index:index+frame_lengths[error_type]])
                index = index+frame_lengths[error_type]
            frames.append(frame)
        
        # Return list of frames
        return frames
    
    
    
    # Function to calcuate checksum
    # Checksum frame is added to the list of frames
    def calculate_checksum(self, frames):
        
        # Initialize checksum by 0
        checksum = '0'
        # Calculate frame length
        frame_len = len(frames[0])

        # Add each frame to checksum
        for frame in frames:
            carry = 0
            if len(bin(int(checksum,2)+int(frame,2))) is (frame_len+3):
                carry = 1
            checksum = bin((int(checksum,2)+int(frame,2))%(2**frame_len))[2:]
            checksum = bin((int(checksum,2)+carry)%(2**frame_len))[2:]
            
        # Negate the checksum
        checksum = bin((~int(checksum,2))%(2**frame_len))[2:]
        
        # Stuff checksum frame with 0 bits
        checksum = '0'*(frame_len - len(checksum)) + checksum
        
        # Append the checksum to list of frames
        frames.append(checksum)
        
        return frames



    # Function to calculate LRC
    # Longitudinal parity is added to list of frames
    def calculate_LRC(self, frames):
        
        # Initialize parity by 0
        parity = '0'
        # Calculate frame length
        frame_len = len(frames[0])
        # Get Parity
        for frame in frames:
            parity = bin(int(parity,2) ^ int(frame,2))[2:]
        
        # Stuff parity frame with 0 bits
        parity = '0'*(frame_len - len(parity)) + parity
        
        # Append parity to list of frames
        frames.append(parity)
        
        return frames
    
    
    
    # Function to calculate VRC
    # VRC bit is appended to every frame
    def calculate_VRC(self, frames):
        
        # Each frame should contain even number of 1
        for frame_index in range(len(frames)):
            if (frames[frame_index]).count('1')%2 is 1:
                frames[frame_index] += '1'
            else:
                frames[frame_index] += '0'
        
        return frames
    
    
    
    # Function to calculate CRC
    # CRC is appended to every frame
    def calculate_CRC(self, frames):
        
        # Calculate frame length
        frame_len = len(frames[0]) + len(self.crc_generator) - 1
        
        # Calculate CRC for every frame
        for frame_index in range(len(frames)):
            
            # Pad frames by crc size
            frames[frame_index] += '0'*(len(self.crc_generator)-1)
            crc = int(frames[frame_index],2)
            divisor = int(self.crc_generator + '0'*(frame_len-len(self.crc_generator)), 2)
            
            # Binary division using XOR
            while divisor >= int(self.crc_generator,2):
                if len(bin(crc)[2:]) >= len(bin(divisor)[2:]):
                    crc = crc ^ divisor
                divisor = int(divisor/2)
            
            # Add remainder to the frame
            frames[frame_index] = bin((int(frames[frame_index],2) + crc)%(2**frame_len))[2:]
            frames[frame_index] = '0'*(frame_len-len(frames[frame_index]))+frames[frame_index]

        return frames
    
    
    
    # Function to call all other functions
    def send(self, num_crc_frames, path=None, string=None):
        
        # Read String from file
        if path is not None:
            string = self.read_from_file(path)
        print("String :")
        print(string)
        print()
        
        # Make Frames
        frames = self.make_frames(string, num_crc_frames)
        print("Frames : ")
        print(frames)
        print()
        
        # Calculate Checksum
        frames[0] = self.calculate_checksum(frames[0])
        print("Frame after Checksum Calculation :")
        print(frames[0])
        print()
        
        # Calculate LRC
        frames[1] = self.calculate_LRC(frames[1])
        print("Frame after LRC Calculation :")
        print(frames[1])
        print()
        
        # Calculate VRC
        frames[2] = self.calculate_VRC(frames[2])
        print("Frame after VRC Calculation :")
        print(frames[2])
        print()
        
        # Generate CRC
        frames[3] = self.calculate_CRC(frames[3])
        print("Frame after CRC Generation :")
        print(frames[3])
        print()
        
        return frames



#%%

# Reciever Class
# Functions :
#               (0) __init__(frame_len)            : Initialize reciever
#               (1) verify_checksum(frames)        : Function to calculate checksum
#               (2) verify_LRC(frames)             : Verify using Longitudinal
#                                                     Redundancy Check
#               (3) verify_VRC(frames)             : Verify using Vertical
#                                                     Redundancy Check
#               (4) verify_CRC(frames)             : Verify using Cyclic 
#                                                     Redundancy Check
#               (5) frames_to_string(frames)       : Convert Frames to String
#               (6) data_recovery(data_list)       : Perform Max-Voting for
#                                                    each Bit Position to try
#                                                    to Recover Data
#               (6) recieve(frames)                : Function to Recieve
        
class Reciever:
    
    
    
    # Init function
    def __init__(self, crc_generator):
        self.crc_generator = crc_generator
    
    
    
    # Function to calcuate checksum
    def verify_checksum(self, frames):
        
        # Initialize checksum by 0
        checksum = '0'
        # Calculate frame length
        frame_len = len(frames[0])
        
        # Add each frame to checksum
        for frame in frames:
            carry = 0
            if len(bin(int(checksum,2)+int(frame,2))) is (frame_len+3):
                carry = 1
            checksum = bin((int(checksum,2)+int(frame,2))%(2**frame_len))[2:]
            checksum = bin((int(checksum,2)+carry)%(2**frame_len))[2:]
        # Negate the checksum
        checksum = bin((~int(checksum,2))%(2**frame_len))[2:]
        
        # Remove checksum frame
        frames.pop()
        
        # Return the checksum
        return int(checksum) is 0
    
    
    
    # Function to perform LRC
    # LRC frame is removed from list of frames
    def verify_LRC(self, frames):
        
        # Initialize parity by 0
        parity = '0'
       
        # Get Parity
        for frame in frames:
            parity = bin(int(parity,2) ^ int(frame,2))[2:]
        
        # Remove parity from list of frames
        frames.pop()
        
        return int(parity) is 0
    
    
    
    # Function to calculate VRC
    # VRC bit is removed from every frame
    def verify_VRC(self, frames):
        parity = 0
        
        # Each frame should contain even number of 1
        for frame_index in range(len(frames)):
            if (frames[frame_index]).count('1')%2 is 1:
                parity = 1
            frames[frame_index] = frames[frame_index][:-1]
        
        return parity is 0
     # Horizontal_Parity + CRC_Code


    
    # Function to calculate CRC
    # CRC is appended to every frame
    def verify_CRC(self, frames):
        
        # Calculate remainder length
        crc_length = len(self.crc_generator)-1
        crc_error = True
        
        # CRC is removed from end of each frame
        frame_len = len(frames[0])-crc_length
        
        # Calculate CRC for every frame
        for frame_index in range(len(frames)):
            
            crc = int(frames[frame_index],2)
            divisor = int(self.crc_generator + '0'*frame_len, 2)

            # Binary division using XOR
            while divisor >= int(self.crc_generator,2):
                if len(bin(crc)[2:]) >= len(bin(divisor)[2:]):
                    crc = crc ^ divisor
                divisor = int(divisor/2)

            # If CRC is 0, then error has occured
            if int(crc) is not 0:
                crc_error = False
            frames[frame_index] = frames[frame_index][:-crc_length]
        
        return crc_error
       
    
    # Convert frames to string
    def frames_to_string(self, frames):
        
        string = ''
        for frame_index in range(len(frames)):
            string += frames[frame_index]
        return string
        
    # Try to recover data
    def data_recovery(self, data_list):
        
        if len(data_list) is 0:
            return None
        
        recovered_data = ''
        
        # Perform Max-Voting for each bit position
        for bit_index in range(len(data_list[0])):
            num_0 = 0
            num_1 = 0
            
            for data_index in range(len(data_list)):
                if data_list[data_index][bit_index] is '0':
                    num_0 += 1
                else:
                    num_1 += 1
                    
            if num_0 > num_1:
                recovered_data += '0'
            elif num_1 > num_0:
                recovered_data += '1'
            else:
                return None
        
        return recovered_data
                
    
    
    # Function to call all other functions
    def recieve(self, frames):

        data_list = []
        
        print()
        print("Frames Recieved : ")
        print(frames[0])
        # Verify using Checksum
        if self.verify_checksum(frames[0]):
            print("No Error Detected using Checksum")
            string = self.frames_to_string(frames[0])
            string = string[string.index('1'):]
            print("Data : ", string)
            data_list.append(string)
        else:
            print("Error Detected using Checksum")

        print()
        print("Frames Recieved : ")
        print(frames[1])
        # Verify using LRC
        if self.verify_LRC(frames[1]):
            print("No Error Detected using LRC")
            string = self.frames_to_string(frames[1])
            string = string[string.index('1'):]
            print("Data : ", string)
            data_list.append(string)
        else:
            print("Error Detected using LRC")
        
        print()
        print("Frames Recieved : ")
        print(frames[2])
        # Verify using VRC
        if self.verify_VRC(frames[2]):
            print("No Error Detected using VRC")
            string = self.frames_to_string(frames[2])
            string = string[string.index('1'):]
            print("Data : ", string)
            data_list.append(string)
        else:
            print("Error Detected using VRC")
        
        print()
        print("Frames Recieved : ")
        print(frames[3])
        # Verify using CRC Check
        if self.verify_CRC(frames[3]):
            print("No Error Detected using CRC Checking")
            string = self.frames_to_string(frames[3])
            string = string[string.index('1'):]
            print("Data : ", string)
            data_list.append(string)
        else:
            print("Error Detected using CRC Checking")
        
        print()
        print()
        print("Analyzing Recieved Data ......")
        # Try to recover actual data from list of data
        recovered_data = self.data_recovery(data_list)
        if recovered_data is not None:
            print("Data Recovered : ", recovered_data)
        else:
            print("Data Has Been Corrupted Beyond Repair")
    
#%%
        
        
        
# Transmission Medium class
# Functions :
#               (0) __init__() : Initialize transmission medium
#               (1) transmit(frames) : Transmit the frames amd
#                                      Introduce Error
        
class TransmissionMedium:
    
    
    
    # Init function
    def __init__(self, error_probability):
        self.error_probability = error_probability
        
        
        
    # Function to introduce error in same bit positions for all detection type
    def transmit(self, frames):
        
        print()
        print("=============== Transmitting ==============")
        print()

        # Get bit positions that will be toggled
#        toggle_bit = [random.random()<self.error_probability for _ in range(len(frames[0])*len(frames[0][0]))]
        
        toggle_bit = [False]*(len(frames[-1][0]))
        toggle_bit[-1] = True
        toggle_bit[-2] = True
        toggle_bit[-4] = True
        toggle_bit = toggle_bit * len(frames[-1])

        # Introduce error at same bit positions for all detection type
        for type_index in range(len(frames)):
            position_index = 0
            for frame_index in range(len(frames[type_index])):
                for bit_index in range(len(frames[type_index][frame_index])):
                    if toggle_bit[position_index]:
                        # Toggle bit
                        if frames[type_index][frame_index][bit_index] is '0':
                            frames[type_index][frame_index] = frames[type_index][frame_index][:bit_index] + '1' + frames[type_index][frame_index][bit_index+1:]
                        else:
                            frames[type_index][frame_index] = frames[type_index][frame_index][:bit_index] + '0' + frames[type_index][frame_index][bit_index+1:]
                    position_index += 1
        
        # Resurn frames with error
        return frames



#%%

crc_generator        = '1011'
number_of_crc_frames = 5
error_probability    = 0.1
path                 = None #"data.txt"
string               = '111011'
sender               = Sender(crc_generator)
reciever             = Reciever(crc_generator)
medium               = TransmissionMedium(error_probability)

#%%

reciever.recieve(medium.transmit(sender.send(number_of_crc_frames, path=path, string=string)))
