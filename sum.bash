echo "Enter the first number: ";
read num1;
echo "Enter the second number: ";
read num2;
echo "the numbers are $num1 and $num2";
sum=$(($num1+$num2));
echo "Sum:$sum";
if [ $num1 -gt $num2 ]
then
echo "Greatest number is $num1";
else
echo "The greatest num is $num2";
fi