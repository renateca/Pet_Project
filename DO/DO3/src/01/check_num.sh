#!/bin/bash
#read -p "Введите символ: " symb

#Проверка на число
if [[ $1 =~ ^[0-9]+$ ]]; then
    echo "ERROR: The symbol is a number"; exit 1
fi