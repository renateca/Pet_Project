#!/bin/bash

TOKEN="7240075039:AAGohlHDx59PKTiBBn2GciH0K3vWQRaXyAA"
CHAT_ID="1191723807"
URL="https://api.telegram.org/bot${TOKEN}/sendMessage"

# sendMessage() {
#   local message=$1
#   curl -s -X POST $URL -d chat_id=$CHAT_ID -d text="$message"
# }

STATUS="$1"
JOB_NAME="$2"
PROJECT_URL="$3"
COMMIT_REF_NAME="$4"

message="CI/CD Pipeline Status:%0ASTAGE: $JOB_NAME%0ASTATUS: $STATUS%0ACI_PROJECT_URL/pipelines/$CI_PIPELINE_ID/%0ABranch: $COMMIT_REF_NAME"

curl -s -d "chat_id=$CHAT_ID&disable_web_page_preview=1&text=$message" $URL>/dev/null
# sendMessage $message