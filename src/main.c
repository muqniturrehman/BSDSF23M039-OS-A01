#include <stdio.h>
#include <stdlib.h>
#include "../include/mystrfunctions.h"
#include "../include/myfilefunctions.h"

int main() {
    printf("--- Testing String Functions ---\n");

    char src[] = "Hello";
    char dest[50];

    printf("Length of '%s' = %d\n", src, mystrlen(src));
    mystrcpy(dest, src);
    printf("After mystrcpy: %s\n", dest);
    mystrncpy(dest, "World", 3);
    dest[3] = '\0';
    printf("After mystrncpy: %s\n", dest);

    char str1[50] = "Hello ";
    char str2[] = "World!";
    mystrcat(str1, str2);
    printf("After mystrcat: %s\n", str1);

    printf("\n--- Testing File Functions ---\n");

    FILE *fp = fopen("test.txt", "r");
    if (!fp) {
        printf("Could not open test.txt\n");
        return 1;
    }

    int lines, words, chars;
    if (wordCount(fp, &lines, &words, &chars) == 0) {
        printf("File stats: %d lines, %d words, %d chars\n", lines, words, chars);
    }

    char **matches = NULL;
	int count = mygrep(fp, "Hello", &matches);  // pass &matches (char***)
    if (count >= 0) {
        printf("Found %d matches:\n", count);
        for (int i = 0; i < count; i++) {
            printf("%s", matches[i]);
            free(matches[i]);
        }
        free(matches);
    }

    fclose(fp);
    return 0;
}
