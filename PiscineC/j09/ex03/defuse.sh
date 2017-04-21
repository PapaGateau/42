x=`stat -r bomb.txt | cut -d ' ' -f 9`
echo "$x - 1" | bc
