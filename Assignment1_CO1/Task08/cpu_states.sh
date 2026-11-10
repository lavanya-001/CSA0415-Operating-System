#!/bin/bash

echo "CPU States and Protection Demonstration"

echo "Current User:"
whoami

echo "Process ID:"
echo $$

echo "CPU Information:"
lscpu | grep "CPU(s):" | head -1

echo "Current Processes:"
ps -u $USER

echo "System Mode:"
echo "Applications run in User Mode."
echo "Operating System runs in Kernel Mode."

echo "Protection Demonstration Completed"
