#!/bin/sh

NC='\033[0m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
GREEN='\033[1;32m'
BLUE='\033[1;36m'
PURPLE='\033[1;35m'

function greet()						#Function for greeting
{
	echo -e -n "${PURPLE}"
	h=`date +%H`

	if [ $h -lt 12 ]
	then
		echo -n "Good Morning"
	elif [ $h -lt 18 ]
	then
		echo -n "Good Afternoon"
	else
		echo -n "Good Evening"
	fi
	echo -e " BCSE!!${NC}"
}

function newdir()						#Create new directory
{
	if [ -z $1 ]
	then
		echo "Enter Directory Name : "
		read directory
	else
		directory=$1
	fi
	mkdir $directory
}

function editfile()						#Edit a file using vi
{
	vi $1
}

function content()						#Show contents of a file
{
	if [ -z $1 ]
        then 
                echo "Enter File Name : "
                read directory
        else
                file=$1
        fi
	cat $file
}

function info()							#Show information of a file
{
	if [ -z $1 ]
	then
		file=.
	else
		file=$1
	fi
	echo -n -e  "Path  \t\t : \t"
	echo $(readlink -f $file )
	echo -n -e "Size \t\t : \t"
	echo $(stat --printf="%s\n" $file )
	echo -n -e "Modified on \t : \t"
	echo $(date -r $file )
	echo -n -e "Owner \t\t : \t"
	echo $(stat -c "%U" $file )
}

function exitbcse()						#Exit the shell
{
	exit
}

function prompt()						#Shell prompt
{
	echo -e "${YELLOW}$(id -u -n) ${RED}at ${GREEN}$(hostname) ${RED}in ${BLUE}$(pwd)${RED}>${NC} "
}

function showdir()						#Show contents of directory
{
	if [ -z $1 ]
        then 
                directory=.
        else
                directory=$1
        fi
	ls -l --color='yes' $directory
}

function clrscr()						#Clear screen
{
	clear
}

function deldir()						#Delete directory
{
	if [ -z $1 ]
        then 
                echo "Enter Directory Name : "
                read directory
        else
                directory=$1
        fi
	rmdir $directory
}

function del()							#Delete a file
{
	if [ -z $1 ]
        then 
                echo "Enter File Name : "
                read file
        else
                file=$1
        fi
	rm $file
}

function nav()							#Navigate to a directory
{
	cd $1
}

function override()						#Override this shell
{
	echo -n "Enter command to execute : "
	read command
	echo $($command)
}

function help()							#Help menu
{
	echo "Commands available :-"
	echo -e "\t showdir [directory_name]: Displays contents of directory 'directory_name'"
	echo -e "\t newdir directory_name \t : Creates new directory with name 'directory_name'"
	echo -e "\t deldir directory_name \t : Deletes the directory with name 'directory_name'"
	echo -e "\t editfile [file_name] \t : Edit a file"
	echo -e "\t del file_name \t\t : Delete file named 'file_name'"
	echo -e "\t content file_name \t : Prints content of file 'file_name' on the screen"
	echo -e "\t info [file_name] \t : Displays full path, size, last modification date, name of creator of the file 'file_name'"
	echo -e "\t nav directory_name \t : Go to directory directory_name"
	echo -e "\t clrscr \t\t : Clear Screen"
	echo -e "\t override \t\t : Override this shell and access shell /bin/sh directly"
	echo -e "\t help \t\t\t : Display this help menu"
	echo -e "\t exitbcse \t\t : Exit this shell"
}

commands=(newdir editfile content info showdir exitbcse clrscr deldir nav help del override)

greet

while true
do
	prompt
	#read command_main command_opt
	read -e command_main command_opt
	#echo "$command_main $command_opt"
	history -s "$command_main $command_opt"
	if [[ " ${commands[@]} " =~ " ${command_main} " ]]
	then
    		$command_main $command_opt
	else
		echo "Command not recognised. Enter 'help' to show all available commands"
	fi
done


