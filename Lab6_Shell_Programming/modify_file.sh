# Converting to lowercase
lowercase=$(<file1.txt)
echo "${lowercase,,}"

# Removing html tags
sed -i 's/<[^>]*>//g' file1.txt
tags=$(<file1.txt)
echo "${tags,,}"

# Replacing words
sed -i -e 's/SEECS/School of Electrical Engineering and Computer Science/g' file1.txt