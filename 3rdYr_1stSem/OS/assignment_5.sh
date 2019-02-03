#!/bin/sh

echo

echo -n "Enter File Name : "
read file                                       		#Input file name

echo -n "Enter String to Search : "
read str                                        		#Input string to search

occurance=$(grep -c "\<$str\>" $file) 				#If occurance is 0 then exit
if [ $occurance == 0 ]
then
    	echo "There is no String \"$str\" in File \"$file\""
        exit
fi

echo -n "Enter New String for Replacement : "
read newstr							#Input string for replacement

sed -i 's/\<'"$str"'\>/'"$newstr"'/g' $file

