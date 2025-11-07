#!/bin/bash

start=$(date +%s)

TOTAL_FOLDERS=$(ls $1 -p | grep / | wc -l)
FOLD_SEVERITY=""
out=$(sudo du -h "$1" | sort -rh | head -5 | awk '{print" - "$2", "$1}')
IFS=$'\n'
i=0
for var in $out; do
    ((i +=1)) 
PER="$IFS$i $var"
FOLD_SEVERITY+=$PER 
done
TOTAL_FILE=$(sudo find $1 -type f | wc -l)
CONF_FILE=$(sudo find $1 -name "*.conf" | wc -l)
TXT_FILE=$(sudo find $1 -name "*.txt" | wc -l)
EXE_FILE=$(sudo find $1 -type f -executable | wc -l)
LOG_FILE=$(sudo find $1 -name "*.log" | wc -l)
ZIP_FILE=$(sudo find $1 -name "*.zip" -o -name "*.7z" -o -name "*.rar" -o -name "*.tar" | wc -l)
SYM_LINKS=$(sudo find "$1" -type l | wc -l)
TOP_FILES=""
top_severity_file=$(sudo find "$1" -type f -not -path '*/\.*' -exec du -h {} + | sort -hr | head -n 10 )
IFS=$'\n'
i=0
for var in $top_severity_file; do
    ((i += 1))
    file=$(echo "$var" | awk '{print $2}')
    size=$(echo "$var" | awk '{print $1}' | sed -e 's:K: Kb:g' | sed 's:M: Mb:g' | sed 's:G: Gb:g' )
    type=$(echo "$var" | awk '{ tp=split($2,type,".") ; print type[tp] }' )
    TOP_FILES+="$IFS$i - $file, $size, $type"
done
EXE_FILES=""
out_exe_files="$(sudo find "$1" -type f -executable -not -path '*/\.*' -exec du -h {} + | sort -hr | head -n 10 )"
IFS=$'\n'
i=0
for var in $out_exe_files
do
    ((i += 1))
    path=$(echo "$var" | awk '{print $2}')
    size=$(echo "$var" | awk '{print $1}' | sed -e 's:K: Kb:g' | sed 's:M: Mb:g' | sed 's:G: Gb:g' )
    md5=$(md5sum "$path"|  awk '{print $1}')
    EXE_FILES+="\n$i - $path, $size, $md5"
done
nd=$(date +%S)
if ! [[ $(($nd-$start)) -gt 0 ]]; then 
    TIME=$((($nd-$start) * (-1)))
else 
    TIME=$(($nd-$start))
fi
RUNTIME=$(($TIME/1000))
#- -i: игнорировать регистр символов при поиске
#- -v: выводить строки, которые не содержат совпадений
#- -l: выводить только имена файлов, содержащих совпадения
#- -c: выводить только количество строк, содержащих совпадения
#- -r: рекурсивный поиск во всех поддиректориях
#- -n: выводить номера строк, содержащих совпадения
#- -w: искать только целые слова
#- -e: использовать регулярное выражение для поиска
#- -A <число>: выводить строки после найденного совпадения
#- -B <число>: выводить строки перед найденным совпадением
#- -C <число>: выводить строки до и после найденного совпадения
# - --exclude: исключить файлы, соответствующие заданному шаблону
