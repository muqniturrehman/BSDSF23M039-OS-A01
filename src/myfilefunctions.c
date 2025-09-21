#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/myfilefunctions.h"

// Function to count lines, words, and characters in a file
int wordCount(FILE* file, int* lines, int* words, int* chars) {
    if (file == NULL || lines == NULL || words == NULL || chars == NULL) {
        return -1;
    }

    *lines = *words = *chars = 0;
    char c, prev = ' ';

    while ((c = fgetc(file)) != EOF) {
        (*chars)++;

        if (c == '\n') {
            (*lines)++;
        }

        // Word counting logic
        if ((c == ' ' || c == '\n' || c == '\t') && (prev != ' ' && prev != '\n' && prev != '\t')) {
            (*words)++;
        }

        prev = c;
    }

    // Handle last word (if file doesn't end with space/newline)
    if (prev != ' ' && prev != '\n' && prev != '\t') {
        (*words)++;
    }

    rewind(file);  // Reset file pointer
    return 0;
}

// Function to search for lines containing a substring
int mygrep(FILE* fp, const char* search_str, char*** matches) {
    if (fp == NULL || search_str == NULL || matches == NULL) {
        return -1;
    }

    char line[1024];
    int count = 0;
    int capacity = 10;

    *matches = (char**)malloc(capacity * sizeof(char*));
    if (*matches == NULL) {
        return -1;
    }

    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, search_str)) {
            if (count >= capacity) {
                capacity *= 2;
                *matches = (char**)realloc(*matches, capacity * sizeof(char*));
                if (*matches == NULL) {
                    return -1;
                }
            }
            (*matches)[count] = strdup(line);  // Copy line
            count++;
        }
    }

    rewind(fp);  // Reset file pointer
    return count;
}
