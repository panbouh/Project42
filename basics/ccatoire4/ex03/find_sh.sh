find . -name "*.sh" -type f | rev | cut -d/ -f1 | cut -c4- | rev
