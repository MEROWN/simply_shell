#include "parser.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MALLOC_ERR perror("malloc")

char** str_alloc(size_t length)
{
    char** ptr_arr = malloc(length * sizeof(char*));
    if (ptr_arr == NULL) {
        MALLOC_ERR;
        return NULL;
    } else
        return ptr_arr;
}

void str_cut(char* str)
{
    size_t strl = strlen(str);
    if (strl > 0) {
        if (str[strl - 1] == '\n') {
            str[strl - 1] = '\0';
        }
    }
}

size_t word_count(char* str)
{
    size_t word_c = 0;
    char* ptr = str;

    while (*ptr != '\0') {
        ptr += strspn(ptr, " \t");
        if (*ptr == '\0')
            break;
        word_c++;
        ptr += strcspn(ptr, " \t");
    }
    return word_c;
}

char** split_line(char* str)
{
    size_t word_c = word_count(str);
    char** args = str_alloc(word_c + 1); //+1 for NULL at the end
    if (args == NULL)
        return NULL;

    args[0] = strtok(str, " \t");
    args[word_c] = NULL;

    for (size_t i = 1; i < word_c; i++) {
        args[i] = strtok(NULL, " \t");
    }

    return args;
}


