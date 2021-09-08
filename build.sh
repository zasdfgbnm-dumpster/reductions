#!/bin/bash

st=`date +%s%N`

time nvcc -c main.cu \
    -std=c++17 \
    -I . \
    -D__CUDA_NO_HALF_OPERATORS__ \
    -D__CUDA_NO_BFLOAT16_OPERATORS__

et=`date +%s%N` 
compt=`echo "scale=3;($et-$st)/1000000000" | bc -l`
echo 'wall time' $compt 'second'
