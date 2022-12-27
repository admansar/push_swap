#!/bin/bash

x=-2147483648

while [ $x -le 2147483700 ]
do
	echo $x
	echo
	./push_swap  $x 
	((x = x + 1))
done
