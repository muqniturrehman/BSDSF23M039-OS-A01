#include "../include/mystrfunctions.h"

// Function to calculate string length
int mystrlen(const char* s) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

// Function to copy a string
int mystrcpy(char* dest, const char* src) {
    if (dest == NULL || src == NULL) return -1;
    int i = 0;
    while ((dest[i] = src[i]) != '\0') {
        i++;
    }
    return 0;
}

// Function to copy n characters
int mystrncpy(char* dest, const char* src, int n) {
    if (dest == NULL || src == NULL) return -1;
    int i;
    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return 0;
}

// Function to concatenate strings
int mystrcat(char* dest, const char* src) {
    if (dest == NULL || src == NULL) return -1;
    int i = 0, j = 0;
    while (dest[i] != '\0') {
        i++;
    }
    while ((dest[i++] = src[j++]) != '\0');
    return 0;
}
