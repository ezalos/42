find -d \./ -type f -name "*.sh" -ls | rev | cut -d "." -f 2 | cut -d "/" -f 1 | rev
