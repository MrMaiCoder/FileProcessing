#!/bin/bash

find $1 -printf "%s\n" > output
size1M=1048576
size10M=10485760
total=0
for i in $(cat output); do
	let total+=$i
done
if [ $total -lt $size1M ]; then
	echo Low
elif [ $total -ge $size1M ] && [ $total -lt $size10M ]; then
	echo Medium
elif [ $total -ge $size10M ]; then
	echo High
fi
rm output
