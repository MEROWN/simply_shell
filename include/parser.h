#ifndef PARSER_H
#define PARSER_H

#include <stdlib.h>

char** str_alloc(size_t length);
void str_cut(char* str);
size_t word_count(char* str);
char** split_line(char* str);

#endif
