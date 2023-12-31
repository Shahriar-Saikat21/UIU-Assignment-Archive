#!/bin/bash

fileName=''
folderName='output_dir'

while true;do
    if [[ -f $1 || -f "$fileName" ]]; then
        if [ -f $1 ]; then
            fileName=$1
        fi
        mkdir "$folderName"
        while read line;do
            x=$(echo $line | cut -d ' ' -f 1-)
            mkdir "$folderName/$x"
            find . -type f -name "*.$x" -exec cp {} "$folderName/$x" \;
            c=$(find . -type f -name "*$x" | wc -l)
            echo "ext $x count: $c"
        done < $fileName  
        break
    else
        echo "input file doesn't exist ."
        echo "Enter input file:"
        read fileName
    fi
done
