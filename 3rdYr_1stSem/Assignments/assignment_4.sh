read file
read str
o=$(grep -o $str $file | wc -l)
if [ $o == 0 ]
then
	echo "Not Found"
	exit
fi
echo
echo "$o occurance(s) found"
arr=(`grep -o -n $str $file | cut -d : -f 1 | uniq -c`)
for (( i=0; i<${#arr[@]}; i+=2 ))
do
    echo -e "${arr[$i+1]}\t${arr[$i]}"
done
echo
