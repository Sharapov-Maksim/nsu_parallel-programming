#include<stdio.h>
#include<stdlib.h>
#include <time.h>

#define MAX(A, B) (((A) > (B)) ? (A) : (B))
#define MIN(A, B) (((A) > (B)) ? (B) : (A))
#define UP 1
#define DOWN 0

int* readFile(const char* filename, int* size);
void printArrayToFile(const char* filename, int* array, int size);
char* concatStrings(const char* str1, const char* str2);

void sort(int a[], int N, int up);


int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE; // Exit if no filename is provided
    }

    const char* filename = argv[1]; // Get the filename from the first command line argument
    int size;
    int* array = readFile(filename, &size);

    int id;
    
    clock_t start_time = clock();

    sort(array, size, UP);

    clock_t end_time = clock();

    // Calculate elapsed time in seconds
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Elapsed time: %.3f seconds\n", elapsed_time);

    printArrayToFile(concatStrings(filename, ".result"), array, size);
    free(array);
}


