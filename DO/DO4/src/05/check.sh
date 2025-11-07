#!/bin/bash

check() {

    if [ "$#" -ne 1 ]; then
        echo "ERROR: ENTER ONE ARGUMENT"
        exit 1
    fi

    log_dir="../04"
    log_files=($(ls -1 "$log_dir/log_day"*.log))

# Проверяем наличие лог-файлов
    if [ ${#log_files[@]} -eq 0 ]; then
        echo "Нет лог файлов: $log_dir"
        exit 1
    fi
}