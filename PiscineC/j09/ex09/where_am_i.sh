variable=$(ifconfig | grep "inet " | cut -d' ' -f2 | grep -o '[0-9]\{1,3\}\.[0-9]\{1,3\}\.[0-9]\{1,3\}\.[0-9]\{1,3\}')
if test -z "$variable"
then
	echo "Je suis perdu!"
else
	echo $variable | tr ' ' '\n'
fi
