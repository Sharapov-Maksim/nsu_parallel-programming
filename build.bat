
REM build sequential implementation
gcc -O3 -o main-seq -fopenmp .\bitonic_sort_sequential.c .\main.c .\util.c
gcc -O3 -o main-parallel -fopenmp .\bitonic_sort_parallel.c .\main.c .\util.c
