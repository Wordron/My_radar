#!/bin/bash

gcc tests/rand.c
make re

./tests/a.out 10 | cat > tests/file.txt
./my_radar tests/file.txt

clear