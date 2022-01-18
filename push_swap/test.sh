#!/bin/bash

x=1
k=$1
while [ $x -le 20 ]
do
	ARG=$(python3 get_random.py $k); ./push_swap $ARG | wc -l
	x=$(( $x + 1 ))
done