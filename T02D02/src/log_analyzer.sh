#!/bin/bash

$logcount
$ucount

while IFS= read -r line
do
	logcount=$[ $logcount + 1 ]
	FILES=($(echo $line))
	for TOKEN in $FILES
	do		
		UFILES+=($TOKEN)
	done
done < $1
FILES=$(echo "${UFILES[@]}" | tr ' ' '\n' | sort -u | tr '\n' ' ')
for file in $FILES
do
	ucount=$[ $ucount + 1 ]
done
echo $logcount $ucount $logcount
