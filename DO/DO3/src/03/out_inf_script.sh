#!/bin/bash

source inf_script.sh
source colors.sh

function out_inf(){
color
    echo -e "${clr_f[1]}${clr_t[2]}HOSTNAME${NC}        = ${clr_f[3]}${clr_t[4]}$HOSTNAME${NC}"
    echo -e "${clr_f[1]}${clr_t[2]}TIMEZONE${NC}        = ${clr_f[3]}${clr_t[4]}$TIMEZONE${NC}"
    echo -e "${clr_f[1]}${clr_t[2]}USER${NC}            = ${clr_f[3]}${clr_t[4]}$USER${NC}"
    echo -e "${clr_f[1]}${clr_t[2]}OS${NC}              = ${clr_f[3]}${clr_t[4]}$OS${NC}"
    echo -e "${clr_f[1]}${clr_t[2]}DATE${NC}            = ${clr_f[3]}${clr_t[4]}$DATE${NC}"
    echo -e "${clr_f[1]}${clr_t[2]}UPTIME${NC}          = ${clr_f[3]}${clr_t[4]}$UPTIME${NC}"
    echo -e "${clr_f[1]}${clr_t[2]}UPTIME_SEC${NC}      = ${clr_f[3]}${clr_t[4]}$UPTIME_SEC${NC}"
    echo -e "${clr_f[1]}${clr_t[2]}IP${NC}              = ${clr_f[3]}${clr_t[4]}$IP${NC}"
    echo -e "${clr_f[1]}${clr_t[2]}MASK${NC}            = ${clr_f[3]}${clr_t[4]}$MASK${NC}"
    echo -e "${clr_f[1]}${clr_t[2]}GATEWAY${NC}         = ${clr_f[3]}${clr_t[4]}$GATEWAY${NC}"
    echo -e "${clr_f[1]}${clr_t[2]}RAM_TOTAL${NC}       = ${clr_f[3]}${clr_t[4]}$RAM_TOTAL GB${NC}"
    echo -e "${clr_f[1]}${clr_t[2]}RAM_USED${NC}        = ${clr_f[3]}${clr_t[4]}$RAM_USED GB${NC}"
    echo -e "${clr_f[1]}${clr_t[2]}RAM_FREE${NC}        = ${clr_f[3]}${clr_t[4]}$RAM_FREE GB${NC}"
    echo -e "${clr_f[1]}${clr_t[2]}SPACE_ROOT${NC}      = ${clr_f[3]}${clr_t[4]}$SPACE_ROOT MB${NC}"
    echo -e "${clr_f[1]}${clr_t[2]}SPACE_ROOT_USED${NC} = ${clr_f[3]}${clr_t[4]}$SPACE_ROOT_USED MB${NC}"
    echo -e "${clr_f[1]}${clr_t[2]}SPACE_ROOT_FREE${NC} = ${clr_f[3]}${clr_t[4]}$SPACE_ROOT_FREE MB${NC}"
}

out_inf
