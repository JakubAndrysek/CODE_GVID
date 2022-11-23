#!/bin/bash
filename='oteoceni-pozpatku.txt'
n=1
while read line; do
# reading each line
tac <<< "$line"
done < $filename | tac 