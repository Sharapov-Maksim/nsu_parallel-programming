#include <stdio.h>

#define DEBUG 0

#define UP 1
#define DOWN 0

int NUM_THREADS = 0;

/*The parameter dir indicates the sorting direction, UP
   or DOWN; if (a[i] > a[j]) agrees with the direction,
   then a[i] and a[j] are interchanged.*/
void compAndSwap(int a[], int i, int j, int dir)
{
    if (dir==(a[i]>a[j]))
        swap(&a[i],&a[j]);
}

void swap(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}
 
/*It recursively sorts a bitonic sequence in ascending order,
  if dir = UP, and in descending order otherwise (means dir=DOWN).
  The sequence to be sorted starts at index position low,
  the parameter cnt is the number of elements to be sorted.*/
void bitonicMerge(int a[], int low, int cnt, int dir)
{
    if (cnt>1)
    {
        int k = cnt/2;
        // TODO can be done parallel
        //#pragma omp parallel
        {
            //#pragma omp for
            for (int i=low; i<low+k; i++)
                compAndSwap(a, i, i+k, dir);
        }
        bitonicMerge(a, low, k, dir);
        bitonicMerge(a, low+k, k, dir);
    }
}

void bitonicMergeParallel(int a[], int low, int cnt, int dir)
{
    if (cnt>1)
    {
        int k = cnt/2;
        {
            #pragma omp parallel for num_threads(2)
            for (int i=low; i<low+k; i++) {
                compAndSwap(a, i, i+k, dir);
            }
        }
        bitonicMerge(a, low, k, dir);
        bitonicMerge(a, low+k, k, dir);
    }
}
 
/* This function first produces a bitonic sequence by recursively
    sorting its two halves in opposite sorting orders, and then
    calls bitonicMerge to make them in the same order */
void bitonicSort(int a[],int low, int cnt, int dir, int level)
{
    if (cnt>1)
    {
        int k = cnt/2;
        int currentThreads = 2 << level; // number of leaves in binary tree at corresponding level
        int nextLevel = level + 1;
        int newThreads = 2 << (nextLevel - 1);

        if (newThreads <= NUM_THREADS) {
            // having enough threads we can parallelize the recursive calls
            if (DEBUG) {
                printf("Level %d, splitted on 2 parallel parts\n", level);
            }
            #pragma omp parallel sections num_threads(2)
            {
                #pragma omp section
                bitonicSort(a, low, k, UP, nextLevel); // sort in ascending order

                #pragma omp section
                bitonicSort(a, low+k, k, DOWN, nextLevel); // sort in descending order
            }
            // merge whole sequence
            bitonicMergeParallel(a, low, cnt, dir);
        } else {
            // too deep, we cannot effectively parallelize anymore
            bitonicSort(a, low, k, UP, nextLevel); // sort in ascending order
            bitonicSort(a, low+k, k, DOWN, nextLevel); // sort in descending order
            // merge whole sequence
            bitonicMerge(a, low, cnt, dir);
        }
    }
}

void sort(int a[], int N, int up)
{

    NUM_THREADS =  omp_get_max_threads();
    if (DEBUG) {
        printf("Number of threads: %d\n", NUM_THREADS);
    }

    bitonicSort(a,0, N, up, 0);
}
 