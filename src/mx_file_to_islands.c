#include "pathfinder.h"

static char **create_arr(const char *file, int len) {
    int fp = open(file, O_RDONLY);
    char *string = NULL;
    char **result = NULL;
    char buff;

    string = mx_strnew(len); //new string;
    for (int i = 0; read(fp, &buff, 1); i++) {
        if (buff == ',' || buff == '-' || buff == '\n')
            string[i] = '$';
        else
            string[i] = buff;
    }
    string[len] = '\0';
    close(fp);
    result = mx_strsplit(string, '$'); // new array still needed not freed
    free(string); //freeing string;
    return result;
}

char **mx_file_to_islands(const char *file) {
    int fp = open(file, O_RDONLY);
    int len = 0;
    char buff;
    char **result;

    if (read(fp, NULL, 0) < 0 || fp == -1)
        return NULL;
    while (read(fp, &buff, 1))
        len++;
    close(fp);
    return create_arr(file, len);
}
