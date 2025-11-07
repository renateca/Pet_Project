#!/bin/bash

function generate_DIRname(){
    local result=$1
    local num=$2
    local last_char=${result: -1}


    for ((i=0; i<$num; i++)); do
        result=${result}$last_char
    done

    result=${result}_${current_date}
    echo $result
}

function generate_FILEname(){
    local name=$FILENAME
    local num=$2
    local last_char=${name: -1}

    for ((i=0; i<$num; i++)); do
        name=${name}${last_char}
    done

    name=${name}_${current_date}.${EXTENSION}
    echo $name
}

function generate_DIR(){

    local DIR_PATH=$1
    local DIR_NAME=$2

    if [ ! -d "${DIR_PATH}/${DIR_NAME}" ]; then
        mkdir -p ${DIR_PATH}/${DIR_NAME}
        return 0
    else
        return 1

    fi
}   


function generate_FILE(){

    local FL_PATH=$1
    local FL_NAME=$2
    local FL_SIZE=$3

    if [ ! -d ${FL_PATH}/${FL_NAME} ]; then
        touch ${FL_PATH}/${FL_NAME}
        fallocate -l $FL_SIZE ${FL_PATH}/${FL_NAME}
        return 0
    else 
        return 1
    fi
}

function generate_FILES(){

    local FL_PATH=$1
    local FL_NUM=$2
    local FL_ALP=$3
    local FL_SIZE=$4
    local FL_NAME

    for ((i=0; i<$FL_NUM; i++)); do
        FREE_MEM=$(df -k / | awk '{print $4}' | tail -n 1)

        if [[ $FREE_MEM -le 1048576 ]]; then
            echo "There is less than 1 GB of free space left"; >&2
            exit 1
        else 
            FL_NAME=$(echo $(generate_FILEname $FL_ALP $i))
            generate_FILE ${FL_PATH} ${FL_NAME} "$FILE_SIZE" 
            if [[ $? -eq 1 ]]; then
                ((FL_NUM++))
            fi
        fi
    done
}   

function run(){

    local FL_NUM=$NUM_DIRS
    local DIR_NAME

    for ((i=0; i<FL_NUM; i++)); do
        FREE_MEM=$(df -k / | awk '{print $4}' | tail -n 1 )

        if [[ $FREE_MEM -le 1048576 ]]; then 
            echo "There is less than 1 GB of free space left"; >&2
            exit 1
        else
            DIR_NAME=$(echo $(generate_DIRname $DIR_LETTERS $i))
            generate_DIR $BASE_PATH $DIR_NAME
            if [[ $? -eq 1 ]]; then
                ((FL_NUM++))
                continue
            fi
            generate_FILES "${BASE_PATH}/${DIR_NAME}" $FL_NUM $FILE_LETTERS $FILE_SIZE

            fi
    done
}

# export BASE_PATH=$1
# export NUM_DIRS=$2
# export DIR_LETTERS=$3
# export NUM_FILES=$4
# export FILE_LETTERS=$5
# export FILE_SIZE=$6