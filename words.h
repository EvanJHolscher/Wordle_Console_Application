#include <stdbool.h>

#ifndef WORDS_H
#define WORDS_H

const char* randomWord();
bool isaWord(char* test);

extern int word_count;

void print_solutions();

#endif
