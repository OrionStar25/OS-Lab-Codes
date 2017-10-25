#!/bin/bash

echo "Enter a number"
read n

rem=$(($n % 2))
if [ $rem -eq 0 ]; then
	#statements
	echo "Its even"
else
	echo "Its odd"	
fi

exit