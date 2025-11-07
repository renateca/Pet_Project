#!/bin/bash

source system_inf.sh

function out_system_inf {

    WHITE_T="\033[37m";
    RED_T="\033[31m";
    GREEN_T="\033[32m";
    BLUE_T="\033[36m";
    PURPLE_T="\033[35m";
    BLACK_T="\033[30m";
    NC="\033[0m";

    echo -e "${PURPLE_T}Total number of folders (including all nested ones)${NC} = $TOTAL_FOLDERS"
    echo -e "${PURPLE_T}TOP 5 folders of maximum size arranged in descending order (path and size):${NC} ${GREEN_T}$FOLD_SEVERITY${NC}"
    echo -e "${PURPLE_T}Total number of files${NC} = $TOTAL_FILE"
    echo -e "${PURPLE_T}Number of:${NC}"  
    echo -e "${BLUE_T}Configuration files (with the .conf extension)${NC} = $CONF_FILE" 
    echo -e "${BLUE_T}Text files${NC} = $TXT_FILE"
    echo -e "${BLUE_T}Executable files${NC} = $EXE_FILE"
    echo -e "${BLUE_T}Log files (with the extension .log)${NC} = $LOG_FILE"  
    echo -e "${BLUE_T}Archive files${NC} = $ZIP_FILE"  
    echo -e "${BLUE_T}Symbolic links${NC} = $SYM_LINKS"
    echo -e "${PURPLE_T}TOP 10 files of maximum size arranged in descending order (path, size and type)${NC}:${GREEN_T}$TOP_FILES${NC}"   
    echo -e "${PURPLE_T}TOP 10 executable files of the maximum size arranged in descending order (path, size and MD5 hash of file)${NC}:${GREEN_T}$EXE_FILES${NC}"
    echo -e "${PURPLE_T}Script execution time (in seconds)${NC} =${GREEN_T}0.$RUNTIME sec${NC}"
} 

out_system_inf
