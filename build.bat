
REM build sequential implementation
gcc -o main-seq -fopenmp .\bitonic_sort_sequential.c .\main.c .\util.c
