#cat $1 | grep -i "nicolas\tbomber"
cat $1 | grep -i "nicolas" | grep -i "bomber" | cut -d" " -f4
