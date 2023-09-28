read a b
c=$[ $a - $b ]
if [ $c == 1 ] || [ $c == -1 ]; then
	a=$[ $a - 1 ]
	b=$[ $b - 1 ]
	if [ $[$a/3] == $[$b/3] ]; then
		echo Yes
	else
		echo No
	fi
else
	echo No
fi
