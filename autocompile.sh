#!/bin/bash

while true; do
	clear

	if cc -Wall -Wextra -Werror -g *.c -o gnl; then
	./gnl
	fi

	sleep 2  
done
