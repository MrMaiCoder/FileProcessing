#!/bin/bash
if [ -e $1 ];then
	lines="$(cat $1)"
	printf %s "$lines" | while IFS= read -r -N 1 i; do
	if [[ "$i" == $'\n' ]]; then
		echo ""
		echo -n "$i"
	else
		echo -n "$i"
	fi
done
fi

