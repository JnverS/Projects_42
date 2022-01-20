#!/bin/bash
YELLOW='\033[38;05;228m'
GREEN='\033[38;05;120m'
RED='\033[38;05;203m'
BLACKBACK='\033[48;05;232m'
ENDCOLOR="\033[0m"
x=1
k=$1
cou=0;
retry=100
max=0;
min=90000000000
while [ $x -le $retry ]
do
	ARG=$(python3.7 get_random.py $k)
	./push_swap $ARG | ./checker_Mac $ARG
	# cur=$(./push_swap $ARG | wc -l)
	# let cou=$(($cou+$cur))
	# if [ $cur -gt $max ]; then
	# max=$cur
	# fi
	# if [ $cur -le $min ]; then
	# min=$cur
	# fi
	x=$(( $x + 1 ))
done
# cou=$(($cou/$retry));
# echo -e '| '$BLACKBACK'max -> '$RED $max$ENDCOLOR '\t|'
# echo -e '| '$BLACKBACK'avr -> '$YELLOW $cou$ENDCOLOR '\t|'
# echo -e '| '$BLACKBACK'min -> '$GREEN $min$ENDCOLOR '\t|'