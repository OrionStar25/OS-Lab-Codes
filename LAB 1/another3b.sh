#!/bin/bash

var=1
while [ $var -eq 1 ]; 
do
	#statements
	echo "Do you want to enter a file name? Y/N"
	read answer
	if [ "$answer" = "Y" -o "$answer" = "y" ];
	then
		#statements
		echo "Enter a file name"
		read filename
		if [ -f $filename ]; 
		then
			#statements
			ucfile=$(echo $filename | tr '[:upper:]' '[:lower:]')
			if [ $ucfile != $filename ];
			then
				#statements
				mv $filename $ucfile 
			fi
		else
			echo "Invalid file name"	
		fi
	else
		break	
	fi
done

exit