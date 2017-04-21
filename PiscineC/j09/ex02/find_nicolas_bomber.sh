if [ $# -eq 1 ]; then
cat $1 | grep -i 'nicolas' | grep -i 'bomber' | grep -v 'nicolasbomber@' | grep -o '[0-9]*\(-[0-9]*\)\{1,\}'
fi
