stat -r	bomb.txt | cut -d' ' -f9 | { read n; echo $(($n-1)); }
