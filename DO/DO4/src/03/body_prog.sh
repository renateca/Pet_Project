#!/bin/bash

export RM="rm -rf"


function delete_by_log() {
    local LOG_FILE
    local cut_line
    echo "Введите путь к лог-файлу"
    read LOG_FILE
    if [ -f "$LOG_FILE" ]; then
        while read -r line; do
            cut_line=$(echo "$line" | awk '{print $1}')
            if [ -f $cut_line ]; then
                $RM $cut_line
                echo "${cut_line} удалено"
            fi
        done < "$LOG_FILE"
    else
        echo "Лог-файл не найден"
    fi
}

function delete_by_date() {
    local start_datetime
    local end_datetime
    
    echo "Введите начальную дату и время (формат: ГГГГ-ММ-ДД чч:мм):"
    read start_datetime
    echo "Введите конечную дату и время (формат: ГГГГ-ММ-ДД чч:мм):"
    read end_datetime

    mapfile -t arr < <(find / -newermt "$start_datetime" ! -newermt "$end_datetime"  2>/dev/null)
    for i in "${arr[@]}"
    do
        $RM $i
        echo "${i} удалено"
    done
    
    
}
check_mask() {
    if ! [[ "$mask" =~ ^[a-zA-Z_]+\_[0-9]{6}$ || "$mask" =~ ^[a-zA-Z_]+\.[a-zA-Z]+\_[0-9]{6}$ ]]; then
         echo "Error:: Некорректный формат маски"
         exit 1
    fi
}

check_freespace(){
    echo "Свободного места на жестком диске: `df -h / | awk 'NR==2 {print $4}'
`"
}

function delete_by_mask() {
    read -p "Введите маску в таком формате foldername_$(date '+%d%m%y'): " mask
    check_mask
    
    check_freespace
    echo "Ищеи и удаляем файлы по маске $mask..."
    
    find / -type f -name "*$mask*" 2>/dev/null | xargs sudo rm -f
    find / -type d -name "*$mask*" 2>/dev/null | xargs sudo rm -rf
    
    check_freespace
    echo "Удаление завершено."
}