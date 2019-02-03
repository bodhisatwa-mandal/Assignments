#!/bin/sh

echo

files=($1 $2 $3 $4)									#Files entered as command line arguments
strings=("echo" "for" "find")								#Strings to search

echo "-------------------------------------------------------------------------"
echo -e "|\tFile/String\t||\t${strings[0]}\t|\t${strings[1]}\t|\t${strings[2]}\t|"
echo "-------------------------------------------------------------------------"

for file in ${files[*]}									#Iterate over all files
do
	echo -n -e "|\t$file\t||"
	for string in ${strings[*]}							#Iterate over all strings
	do
		occurance=$(grep -c "\<$string\>" $file)				#Get occurance of a string in a file(exact match)
		echo -n -e "\t$occurance\t|"						#Print occurance
	done
	echo
done

echo "-------------------------------------------------------------------------"
echo
