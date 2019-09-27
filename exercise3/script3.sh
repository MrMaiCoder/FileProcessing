#!/bin/bash
location=$( pwd )
for i in "$location"/*;do
	if [ -f $file ];then
		echo "$i"
	fi
done

