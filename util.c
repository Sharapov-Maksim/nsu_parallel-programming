#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int* readFile(const char* filename, int* size) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Failed to open file");
        return NULL; // Return NULL if the file cannot be opened
    }

    // Read the number of elements
    if (fscanf(file, "%d", size) != 1) {
        perror("Failed to read the number of elements");
        fclose(file);
        return NULL; // Return NULL if reading fails
    }

    // Allocate memory for the array
    int* array = (int*)malloc(*size * sizeof(int));
    if (array == NULL) {
        perror("Failed to allocate memory");
        fclose(file);
        return NULL; // Return NULL if memory allocation fails
    }

    // Read the integers into the array
    for (int i = 0; i < *size; i++) {
        if (fscanf(file, "%d", &array[i]) != 1) {
            perror("Failed to read integer");
            free(array); // Free allocated memory on error
            fclose(file);
            return NULL; // Return NULL if reading fails
        }
    }

    fclose(file); // Close the file
    return array; // Return the allocated array
}

void printArrayToFile(const char* filename, int* array, int size) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        perror("Failed to open file");
        return; // Exit if the file cannot be opened
    }

    // Write the size of the array
    fprintf(file, "%d\n", size);

    // Write the elements of the array
    for (int i = 0; i < size; i++) {
        fprintf(file, "%d ", array[i]);
    }
    fprintf(file, "\n"); // New line after the array elements

    fclose(file); // Close the file
}

// Function to concatenate two strings
char* concatStrings(const char* str1, const char* str2) {
    // Calculate the length of the new string
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    
    // Allocate memory for the concatenated string (+1 for the null terminator)
    char* result = (char*)malloc(len1 + len2 + 1);
    if (result == NULL) {
        perror("Failed to allocate memory");
        return NULL; // Return NULL if memory allocation fails
    }

    // Copy the first string into the result
    strcpy(result, str1);
    // Concatenate the second string
    strcat(result, str2);

    return result; // Return the concatenated string
}
