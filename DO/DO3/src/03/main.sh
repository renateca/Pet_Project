#!/bin/bash

if [[ $# -ne 4 ]]; then
    echo "invalid number of arguments"; exit 1
else
    source check_arg.sh

    export param1=$1
    export param2=$2
    export param3=$3
    export param4=$4

    source out_inf_script.sh

fi


