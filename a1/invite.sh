#!/bin/bash

year=2019
birthyear=0

for i in $(cat $1); do
	echo $i &> tmp
	let birthyear=$(cut -d ',' -f 3 tmp | cut -c1-4)
	let age=$((year-birthyear))
	if [ $age -ge 18 ];then
		names=''
		names+=$(cut -d ',' -f 2 tmp)
		names+=', '
		names+=$(cut -d ',' -f 1 tmp)
		echo $names &>> list
	fi
done

while read -r line; do
	echo "Dear Mr/Mrs $line"
done < list
rm tmp list
