#!/bin/bash

echo Enter a word
read word
echo Enter the filename
read file
number=$(grep -c $word $file)
echo $number "times" $word "present in" $file