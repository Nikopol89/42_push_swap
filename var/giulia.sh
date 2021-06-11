#!/bin/bash

perm() {
	local items="$1"
	local out="$2"
	local i
	[[ "$items" == "" ]] && echo "$out" && ./push_swap "$out" | wc -l && ./push_swap "$out" | ./var/checker_linux "$out" && return
	for (( i=0; i<${#items}; i++ )) ; do
		perm "${items:0:i}${items:i+1}" "$out ${items:i:1}"
	done
}

test() {
	local number="$1"
	local iniitem="$(seq -s' ' 1 ${number} | sed -n 's/ //g;p')"
	perm "$iniitem"
}

echo "Immettere un numero: "
read N
test $N