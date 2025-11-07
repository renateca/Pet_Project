#!/bin/bash

function color {
    clr[1]=$param1;
    clr[2]=$param2;
    clr[3]=$param3;
    clr[4]=$param4;
    
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

    NC="\033[0m"; # No Color

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