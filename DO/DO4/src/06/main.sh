#!/bin/bash

path="../04"

for (( i=1; i<6; i++ )); do
    if [[ -f "${path}/log_day$i.log" ]]; then 
        flag=1
    else 
        flag=0
        echo "ERROR: ${path}/log_day$i.log файла не существует!"
        break
    fi
done

if [[ $flag -eq 1 ]]; then
    sudo apt install -y goaccess
    goaccess ${path}/*.log --log-format=COMBINED --time-format=%T -o report.html
fi
