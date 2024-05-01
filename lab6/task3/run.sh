#!/usr/bin/env bash

if gcc -c function.s; then      
    if g++ -Wall -Wextra main.cpp function.o -o main; then
        ./main
    fi
fi