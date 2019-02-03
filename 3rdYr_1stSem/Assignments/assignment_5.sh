read file
read str
o=$(grep -c $str $file)
if [ $o == 0 ]
then
    	echo "Not Found"
        exit
fi
read newstr
sed -i 's/\<'"$str"'\>/'"$newstr"'/g' $file

