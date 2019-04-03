import random
from scipy.linalg import hadamard
#%%

class Station:
	def __init__(self, station_id, num_stations, code):
		self.num_stations = num_stations
		self.station_id = station_id
		self.code = code
		self.data = ""
		self.data_id = 0

	def get_Data(self):
		self.data = input()

	def send_Data(self):
		bit = str(self.data)[self.data_id]
		if bit == 'i':
			bit = 0
		elif int(bit) == 0:
			bit = -1
		else:
			bit = 1
		self.data_id += 1
		self_code = [0]*len(self.code)
		for i in range(len(self_code)):
			self_code[i] = bit*self.code[i]
		print("Station", self.station_id, "Sending Data", self_code)
		return self_code


class CDMA:
	def __init__(self, num_stations, bit_len):
		self.buffer = 0
		self.walsh_code = []
		self.num_stations = num_stations
		self.stations = []
		self.bit_len = bit_len

	def generate_Walsh_Code(self):
		self.walsh_code = [[int(bin(x&y),13)%2or-1for x in range(self.num_stations)]for y in range(self.num_stations)]
		#hadamard(self.num_stations)
		print("Walsh Code")
		print(self.walsh_code)

	def create_Stations(self):
		for station_id in range(self.num_stations):
			station = Station(station_id, num_stations, self.walsh_code[station_id])
			print("Enter Bit Stream for Station", station_id, ":")
			station.get_Data();
			self.stations.append(station)

	def show_Code(self):
		for bit_index in range(self.bit_len):
			print()
			print("=============================")
			print("For Bit : ",bit_index)
			temp_sum = [0]*len(self.walsh_code[0])
			for station_index in range(self.num_stations):
				temp_code = self.stations[station_index].send_Data()
				print("Code Received from Station ",station_index," : ",temp_code)
				for i in range(len(temp_code)):
					temp_sum[i] += temp_code[i]
			print("Final Code Received : ", temp_sum)

			for station_index in range(self.num_stations):
				sum_code=0
				#print()
				#print("walsh", self.walsh_code[station_index])
				#print()
				for i in range(len(temp_sum)):
					sum_code += temp_sum[i]*self.walsh_code[station_index][i]
				sum_code /= self.num_stations
				if sum_code == 0:
					sum_code = 'i'
				elif sum_code == -1:
					sum_code = 0
				else:
					sum_code = 1
				print("Bit Received from Station :", station_index, " : ",sum_code)
#%%
print("Enter Number of Stations")
num_stations = int(input())
print("Enter Bit Length")
bit_len = int(input())
cdma = CDMA(num_stations, bit_len)
cdma.generate_Walsh_Code()
cdma.create_Stations()
cdma.show_Code()

