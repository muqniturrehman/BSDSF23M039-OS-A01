#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/myfilefunctions.h"

// Count lines, words, and characters
int wordCount(FILE* file, int* lines, int* words, int* chars) {
    if (!file || !lines || !words || !chars) return -1;

    *lines = *words = *chars = 0;
    char c, prev = ' ';

    while ((c = fgetc(file)) != EOF) {
        (*chars)++;
        if (c == '\n') (*lines)++;
        if ((c == ' ' || c == '\n' || c == '\t') &&
            (prev != ' ' && prev != '\n' && prev != '\t')) {
            (*words)++;
        }
        prev = c;
    }

    if (prev != ' ' && prev != '\n' && prev != '\t') (*words)++;
    rewind(file);
    return 0;
}

// Grep function matches header signature
int mygrep(FILE* fp, const char* search_str, char*** matches) {
    if (!fp || !search_str || !matches) return -1;

    char line[1024];
    int count = 0, capacity = 10;

    char **out = malloc(capacity * sizeof(char*));
    if (!out) return -1;

    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, search_str)) {
            if (count >= capacity) {
                capacity *= 2;
                char **tmp = realloc(out, capacity * sizeof(char*));
                if (!tmp) {
                    for (int i = 0; i < count; i++) free(out[i]);
                    free(out);
                    return -1;
                }
                out = tmp;
            }
            out[count] = strdup(line);
            if (!out[count]) {
                for (int i = 0; i < count; i++) free(out[i]);
                free(out);
                return -1;
            }
            count++;
        }
    }
    rewind(fp);

    *matches = out;   // assign allocated array to caller
    return count;
}
