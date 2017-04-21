ldapsearch -LLL -Q "uid=z*" cn | grep -v "^$" | grep -v "^dn" | sort -r -f | sed "s/^cn: //"
