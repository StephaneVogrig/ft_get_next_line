#!/bin/bash

while true; do
	clear

	cc -Wall -Wextra -Werror *.c -o gnl
	./gnl

	sleep 5  
done
