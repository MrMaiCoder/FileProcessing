#!/bin/bash

find $2 -type f | grep ".$1" &> filename
for i in $(cat filename`); do
       mv $i ${i%.*}
done      
rm filename
