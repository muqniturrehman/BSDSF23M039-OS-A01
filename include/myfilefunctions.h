
// Count the number of lines, words and chracters in the passed file stream pointer. Return 0 on success and -1 on failure.
int wordcount(FILE* file, int* lines, int* words, int* chars);

// Search lines containing search_str in a file, and fills the matches array. Return the count of matches and -1 on filure. 
int mygrep(FILES* fp, const char* search_str, char** matches);

