#!/bin/bash

time nvcc -c main.cu \
    -std=c++17 \
    --keep -v \
    -I . \
    -D __CUDA_NO_HALF_OPERATORS__ \
    -D __CUDA_NO_BFLOAT16_OPERATORS__
