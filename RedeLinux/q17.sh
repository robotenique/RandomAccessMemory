#!/bin/bash
echo "==> Check if a user is logged on in the LAN"
echo ""
echo "Type the username to verify if it's logged on, then press [ENTER]:"
read user
ret=$(last -w | grep still | awk '{print $1 }' | grep $user)
for x in $ret
do
	if [ $user = $x ]
	then
		echo "YES, the user is logged in!"
		exit
	fi
done
echo "NO, the user isn't logged in!"
