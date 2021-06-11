#!/bin/bash
#
# Bonus checker accepts -v (verbose) flag before arguments
#
# leaks -atExit --

ARG="$(cat ./var/dataset.txt)";

printf "Bonus checker: "
./push_swap 10 $ARG 500 | ./checker 10 $ARG 500

if [[ "$(uname)" = "Linux" ]]
	then
	printf "42 Linux checker: "
	./push_swap $ARG | ./var/checker_linux $ARG
else
	printf "42 Mac Checker: "
	./push_swap $ARG | ./var/checker_Mac $ARG
fi

printf "Total instructions: "
./push_swap $ARG | wc -l
