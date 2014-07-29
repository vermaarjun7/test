#!/bin/bash

#ques1


a= top | awk -F '{print $1}'
echo $a

 


#ques3
echo "take two numbers"
read a
read b



sum=`expr $a + $b`
product=`expr $a * $b`
diff=`expr $a - $b`

echo $sum
echo $product
echo $diff




