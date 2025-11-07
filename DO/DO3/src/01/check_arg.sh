#!/bin/bash

# Проверка колличества аргументов 
if [ $# -ne 1 ]; then
    echo "ERROR: A lot of characters entered"; exit 1
fi