#!/bin/sh

echo

echo -n "Enter File Name : "
read file							#Input file name

echo -n "Enter String to Search : "
read str							#Input string to search

occurance=$(grep -c "\<$str\>" $file)
if [ $occurance == 0 ]						#If occurance is 0 then exit
then
	echo "There is no String \"$str\" in File \"$file\""
	exit
fi
echo
echo "There are $occurance occurance(s) found"			#Display occurances

arr=(`grep -o -n $str $file | cut -d : -f 1 | uniq -c`)

echo
echo "----------------------------------"
echo -e "||     Line     |   Occurance   ||"
echo "----------------------------------"
for (( i=0; i<${#arr[@]}; i+=2 ))				#Display occurances per line
do
    echo -e "||\t${arr[$i+1]}\t|\t${arr[$i]}\t||"
done
echo "----------------------------------"

echo
