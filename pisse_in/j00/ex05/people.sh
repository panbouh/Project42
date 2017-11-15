#bin/sh
ldapsearch -LLL uid=z* cn | grep -ie cn | cut -c5- | sort -rdf
