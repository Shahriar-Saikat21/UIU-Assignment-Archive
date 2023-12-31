#!/bin/bash

func1(){
    echo "enter file name:"
    read file
    if [ -f $file ];then           
        while read line;do
            for i in $line;do
                if [[ $i != [0-9] ]];then
                    c=$(grep -o $i $file | wc -l )
                    echo "word:$i count:$c" 
                fi
            done
        done < $file  
    else
        echo "file does not exist"
    fi
}

func2(){
    echo "Enter words :"
    read line
    echo "Enter replacing word :"
    read word
    echo "enter absolute path of directory:"
    read path
    for i in $line;do
        c=$(grep -o $i $path | wc -l )
        echo "word: $i file_count:$c"
    done
    for i in $line;do
        sed -i"s/$i/$word/g" $path
    done   
}

x=$1

if [ $x -eq 1 ];then
    func1 
elif [ $x -eq 2 ];then
    func2 
else
    echo "Invalid argument"
fi






