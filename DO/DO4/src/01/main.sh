#!/bin/bash

if [ "$#" -ne 6 ]; then 
    echo "INCORRECT NUMBER OF ELEMENTS (THERE SHOULD BE 6 ELEMENTS)"; >&2
    exit 1;
fi
# Параметры скрипта
export BASE_PATH=$1
export NUM_DIRS=$2
export DIR_LETTERS=$3
export NUM_FILES=$4
export FILE_LETTERS=$5
export FILE_SIZE=$6


export current_date=$(date +%d%m%y)
export FILENAME=$(echo $FILE_LETTERS | cut -d'.' -f1)
export EXTENSION=$(echo $FILE_LETTERS | cut -d'.' -f2)

source valid.sh "$@"


source body_program.sh

run




