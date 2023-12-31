#!/bin/bash

echo 'Enter number of inputs:'
read n

for (( i=0; i<$n; i++ ));do
    echo 'Enter file name:'
    read input
    if [[ $input == *+(.pdf) ]];then
        echo 'Pdf file'
    elif [[ $input == *+(.txt) ]];then
        echo 'Text file'
    elif [[ $input == *+(.jpg|.jpeg|.png) ]];then
        echo 'Image file'
    elif [[ $input == *+(.c) ]];then
        echo 'C file'
    else
        echo 'Unknown file'
    fi  
done


