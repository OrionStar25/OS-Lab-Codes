#!/bin/bash

echo Enter any text
read word

if [ -d $word ];
then
	echo "Its a directory"
elif [ -f $word ];
then
	echo "Its a file"
else
	echo "Its nothing"	
fi

exit	
