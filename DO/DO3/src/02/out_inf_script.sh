#!/bin/bash

source inf_script.sh

function out_inf(){
echo "HOSTNAME = $HOSTNAME"
echo "TIMEZONE = $TIMEZONE"
echo "USER = $USER"
echo "OS = $OS"
echo "DATE = $DATE"
echo "UPTIME = $UPTIME"
echo "UPTIME_SEC = $UPTIME_SEC"
echo "IP = $IP"
echo "MASK = $MASK"
echo "GATEWAY = $GATEWAY"
echo "RAM_TOTAL = $RAM_TOTAL GB"
echo "RAM_USED = $RAM_USED GB"
echo "RAM_FREE = $RAM_FREE GB"
echo "SPACE_ROOT = $SPACE_ROOT MB"
echo "SPACE_ROOT_USED = $SPACE_ROOT_USED MB"
echo "SPACE_ROOT_FREE = $SPACE_ROOT_FREE MB"
}

out_inf

read -p "Do you want to write data to a file?" answer
if [[ $answer = [Yy] ]]; then
    file=$(date +"%d_%m_%Y_%H_%M_%S".status)
    out_inf>$file
    echo "DONE $(date '+%d_%m_%Y_%H_%M_%S').status" 
else
    echo "No data was recorded"
fi