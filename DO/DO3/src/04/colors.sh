#!/bin/bash

if [[ ! -f "config.conf" ]]; then 
    echo "Config not found!"; exit 1
fi 

function def_clr {
    clr[1]=1;
    clr[2]=2;
    clr[3]=3;
    clr[4]=4;
}

function color {
def_clr
# цвет текста  
    WHITE_T="\033[37m";
    RED_T="\033[31m";
    GREEN_T="\033[32m";
    BLUE_T="\033[36m";
    PURPLE_T="\033[35m";
    BLACK_T="\033[30m";

# цввет фона
    WHITE_F="\033[47m";
    RED_F="\033[41m";
    GREEN_F="\033[42m";
    BLUE_F="\033[46m";
    PURPLE_F="\033[45m";
    BLACK_F="\033[40m";

# No Color
    NC="\033[0m";

    Conf_count=0;
    ER_count=0;
    count=0
    err[1]=0
    err[2]=0
    err[3]=0
    err[4]=0

    for i in "column1_background" "column1_font_color" "column2_background" "column2_font_color"; do
        count=$(($count + 1))
        if ! [[ $(grep -c $i config.conf) -eq 1 ]]; then 
            err[$count]=1;
        else 
            clr[$count]=$(grep $i config.conf | awk -F = '{printf("%i", $2)}');
        fi
    done 

    # echo a${clr[1]} b${clr[2]} c${clr[3]} d${clr[4]} r$count

    for i in 1 2 3 4; do 
        if [[ ${clr[$i]} == 1 ]]; then
            color[$i]="(white)"
        elif [[ ${clr[$i]} == 2 ]]; then
            color[$i]="(red)"
        elif [[ ${clr[$i]} == 3 ]]; then
            color[$i]="(green)"
        elif [[ ${clr[$i]} == 4 ]]; then
            color[$i]="(blue)"
        elif [[ ${clr[$i]} == 5 ]]; then
            color[$i]="(purple)"
        elif [[ ${clr[$i]} == 6 ]]; then
            color[$i]="(black)"
        fi
    done

    for i in 1 2 3 4; do
        if ! [[ ${clr[$i]} =~ ^[1-6]+$ ]]; then 
            echo "Arguments entered incorrectly"; exit 1
        fi
    done

    if [[ ${clr[1]} == ${clr[2]} || ${clr[3]} == ${clr[4]} ]]; then
        echo "ERROR: The background and the color of the text cannot be the same!"; exit 1
    fi

    for i in 1 3; do
        if [[ ${clr[$i]} == 1 ]]; then
            clr_f[$i]=$WHITE_F
        elif [[ ${clr[$i]} == 2 ]]; then 
            clr_f[$i]=$RED_F
        elif [[ ${clr[$i]} == 3 ]]; then
            clr_f[$i]=$GREEN_F
        elif [[ ${clr[$i]} == 4 ]]; then
            clr_f[$i]=$BLUE_F
        elif [[ ${clr[$i]} == 5 ]]; then
            clr_f[$i]=$PURPLE_F
        elif [[ ${clr[$i]} == 6 ]]; then
            clr_f[$i]=$BLACK_F
        fi
    done
    
    for i in 2 4; do
        if [[ ${clr[$i]} == 1 ]]; then
            clr_t[$i]=$WHITE_T
        elif [[ ${clr[$i]} == 2 ]]; then 
            clr_t[$i]=$RED_T
        elif [[ ${clr[$i]} == 3 ]]; then
            clr_t[$i]=$GREEN_T
        elif [[ ${clr[$i]} == 4 ]]; then
            clr_t[$i]=$BLUE_T
        elif [[ ${clr[$i]} == 5 ]]; then
            clr_t[$i]=$PURPLE_T
        elif [[ ${clr[$i]} == 6 ]]; then
            clr_t[$i]=$BLACK_T
        fi
    done

}
color