#!/bin/bash

make && ./containers
if cmp -s "res_vector.txt" "res_myvector.txt"; then
	echo -e "\033[0;33m"
	cat res_vector.txt | grep "test"
	echo -e "\033[0m"
	echo -e "\033[0;32mTester Vector ------ ok\n\033[0m"
else
	echo -e "\033[0;31mTester Vector ------ ko\n\033[0m"
	echo -e "lines that are different in res_myvector.txt:"
	diff res_vector.txt res_myvector.txt
fi