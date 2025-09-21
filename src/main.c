#include <stdio.h>
#include <stdlib.h>
#include "../include/mystrfunctions.h"
#include "../include/myfilefunctions.h"

int main() {
    printf("--- Testing String Functions ---\n");

    char src[] = "Hello";
    char dest[50];

    // Test mystrlen
    printf("Length of '%s' = %d\n", src, mystrlen(src));

    // Test mystrcpy
    mystrcpy(dest, src);
    printf("After mystrcpy, dest = %s\n", dest);

    // Test mystrncpy
    mystrncpy(dest, "World", 3);
    dest[3] = '\0'; // Ensure string ends
    printf("After mystrncpy, dest = %s\n", dest);

    // Test mystrcat
    char str1[50] = "Hello ";
    char str2[] = "World!";
    mystrcat(str1, str2);
    printf("After mystrcat, str1 = %s\n", str1);

    printf("\n--- Testing File Functions ---\n");

    FILE *fp = fopen("test.txt", "r");
    if (fp == NULL) {
        printf("Could not open test.txt\n");
        return 1;
    }

    int lines, words, chars;
    if (wordCount(fp, &lines, &words, &chars) == 0) {
        printf("File stats: %d lines, %d words, %d characters\n", lines, words, chars);
    } else {
        printf("wordCount failed!\n");
    }

    char **matches;
    int count = mygrep(fp, "Hello", &matches);
    if (count >= 0) {
        printf("Found %d matching lines:\n", count);
        for (int i = 0; i < count; i++) {
            printf("%s", matches[i]);
            free(matches[i]);  // Free memory for each line
        }
        free(matches);  // Free array of pointers
    } else {
        printf("mygrep failed!\n");
    }

    fclose(fp);

    return 0;
}
