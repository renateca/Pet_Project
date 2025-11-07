#!/bin/bash

scp ${CI_PROJECT_DIR}/src/cat/s21_cat renateca@10.10.0.1:/home/renateca
scp ${CI_PROJECT_DIR}/src/grep/s21_grep renateca@10.10.0.1:/home/renateca
ssh renateca@10.10.0.1 mv s21_cat /usr/local/bin
ssh renateca@10.10.0.1 mv s21_grep /usr/local/bin
ssh renateca@10.10.0.1 ls -ah /usr/local/bin/