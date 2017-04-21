ldapsearch -Q sn="*bon*" | grep "sn:" | wc -l | sed -e 's/^[ \t]*//'
