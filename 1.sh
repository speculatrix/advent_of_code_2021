#!/bin/bash
# https://adventofcode.com/2021
# solver of problem 1
# passes shellcheck

IN_FILE="1_input.txt"
DBG=0

idx=0
rising=0
falling=0

while read -r input_value ; do

	[ $DBG -gt 0 ] && echo "idx $idx value $input_value"
	if [ $idx -gt 0 ] ; then
		if [ "$input_value" -gt "$old_input_value" ] ; then
			[ $DBG -gt 0 ] && echo "rising"
			rising=$(( rising + 1 ))
		elif [ "$input_value" -lt "$old_input_value" ] ; then
			[ $DBG -gt 0 ] && echo "falling"
			falling=$(( falling + 1 ))
		fi
	fi

	idx=$(( idx + 1 ))
	old_input_value="$input_value"

done < $IN_FILE

cat <<EOF
count: $idx
rising: $rising
falling: $falling 
EOF
