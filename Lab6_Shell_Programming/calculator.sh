# Calculator
result=0
choice="y"
while [ $choice = "y" ]
do
echo "Enter first number"
read num1
echo "Enter second number"
read num2

echo "1.Addition"
echo "2.Subtraction"
echo "3.Multiplication"
echo "4.Division"
echo "Enter your choice"
read operation
case $operation in
    1)result=`expr $num1 + $num2`
     echo "Sum ="$result;;
    2)result=`expr $num1 - $num2`
     echo "Sub = "$result;;
    3)result=`expr $num1 \* $num2`
     echo "Mul = "$result;;
    4)result=`expr $num1 / $num2`
     echo "Div = "$result;;
   *)echo "Invalid choice";;
esac
echo "Do u want to continue ?"
read choice
if [ $choice != "y" ];
then
    exit
fi
done
