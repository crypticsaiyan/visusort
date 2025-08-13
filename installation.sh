#!/bin/bash

# Compile all .cpp files in current directory and subdirectories
g++ -O3 -s $(find . -name "*.cpp") -o main
