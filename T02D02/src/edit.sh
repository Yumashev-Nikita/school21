#!/bin/bash

SHA1=$(shasum -a 256 $1 | awk '{print $1}')
sed -i '' 's/'$2'/'$3'/g' $1
SHA2=$(shasum -a 256 $1 | awk '{print $1}')

if [[ "$SHA1" != "$SHA2" ]]; then
	SIZE=$(wc -c $1 | awk '{print $1}')
	DATE=$(date '+%Y-%m-%d %H:%M')
	echo 'src/'$1' - '$SIZE' - '$DATE' - '$SHA2' - sha256' >> files.log
	echo 'yes'
fi

