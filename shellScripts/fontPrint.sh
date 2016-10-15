#Generate unicode commands to print in the terminal.
# With this, you can check the icons your default font have..
x='0 1 2 3 4 5 6 7 8 9 A B C D E'
y='0 1 2 3 4 5 6 7 8 9 A B C D E F'
z='0 1 2 3 4 5 6 7 8 9 A B C D E F'
tx='\u'
for i in $x; do
	for j in $y; do
		for k in $z; do
			(echo -n echo \'$tx$i$j$k\' && echo -n "&& " && echo sleep 0.2)
		done
	done
done