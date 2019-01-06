# Displaying Multiplication table
echo "Enter a number"
read num;

echo "Multiplication table for $num"
limit=4
for i in $(seq 1 $limit); do
	echo "$num x $i = $(($num * $i))"
done
