#!/bin/bash

(ls $1) &> output.txt
result=$(cat output.txt)
if [ "$result" = "$1" ]; then
	echo "File Exist"
else
	echo "File Does Not Exist"
fi

