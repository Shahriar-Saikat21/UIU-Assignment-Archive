#!/bin/bash

sum=0
x=$#
if [ $x -gt 0 ];then
    for arg in $@;do
        sum=$(($sum+$arg))
    done
    echo "sum : $sum"
else
    echo 'enter n'
    read n
    for (( i=1; i<=n; i++));do
        echo "enter number $i:"
        read x
        sum=$(($sum+$x))
    done
    echo "sum: $sum" 
fi

    


