#!/bin/bash
curl -s https://en.wikipedia.org/wiki/World_Happiness_Report?action=raw -o text.txt
for i in 1 2 3 4 5 6 7 8 9 10; do
	country= grep "| $i||{{flag" text.txt | cut -f5 -d "|" | tr -d "}"
done

