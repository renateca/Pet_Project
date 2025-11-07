#!/bin/bash

if ! [[ $1 =~ ^[1-6]+$ ]]; then 
    echo "Arguments entered incorrectly"; exit 1
elif ! [[ $2 =~ ^[1-6]+$ ]]; then
    echo "Arguments entered incorrectly"; exit 1
elif ! [[ $3 =~ ^[1-6]+$ ]]; then
    echo "Arguments entered incorrectly"; exit 1
elif ! [[ $4 =~ ^[1-6]+$ ]]; then
    echo "Arguments entered incorrectly"; exit 1
fi

if [[ $1 == $2 || $3 == $4 ]]; then
    echo "ERROR: The background and the color of the text cannot be the same! Repeat the input."; exit 1  
fi