#!/bin/bash

# function check_arg{

if [[ $BASE_PATH != /* || ! -d $BASE_PATH ]]; then
    echo "THE WRONG ABSOLUTE PATH"; >&2
fi

if ! [[ $NUM_DIRS =~ ^[0-9]+$ ]] ; then
    echo "INCORRECT NUMBER OF DIRS $2"; >&2
fi

if ! [[ $NUM_FILES =~ ^[0-9]+$ ]] ; then
    echo "INCORRECT NUMBER OF DIRS $4"; >&2
fi

if ! [[ $DIR_LETTERS =~ ^[A-Za-z]{1,7}$ ]] ; then
    echo "INCORRECT NUMBER OF DIRS $3"; >&2
fi

if ! [[ $FILE_LETTERS =~ ^[A-Za-z]{1,7}\.[A-Za-z]{1,3}$ ]] ; then
    echo "INCORRECT NUMBER OF DIRS $5"; >&2
fi

if ! [[ $FILE_SIZE =~ '^[0-9]+kb$' || ${6%kb} -gt 100 ]] ; then
    echo "INCORRECT NUMBER OF DIRS $6"; >&2
fi

# }

# check_arg