#!/bin/bash

if ! [[ $# -eq 1 ]]; then
    echo "ERROR: too many arguments!"; exit 1
elif [[ ${1: -1} != "/" ]]; then 
    echo "ERROR: wrong way!"; exit 1
else 
    source out_system_inf.sh
fi