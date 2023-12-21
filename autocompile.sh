#!/bin/bash

while true; do
	clear
	#norminette
	#if cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=1 main.c get_next_line.c get_next_line_utils.c -o gnl; then
	#if cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c -o gnl; then
	#if cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=9999 main.c get_next_line.c get_next_line_utils.c -o gnl; then
	if cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=10000000 main.c get_next_line.c get_next_line_utils.c -o gnl; then
	./gnl
	fi

	sleep 2  
done
