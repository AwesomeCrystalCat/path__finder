#include "pathfinder.h"

char **mx_find_uniques(char **str) {
    int len = mx_positive_atoi(str[0]);
    int n = 0;
    char **uniques = (char **)malloc(sizeof(char *) * (len)); //initialize array of pointers

    uniques[len] = NULL;
    for (int i = 0; i < len; i++)
        uniques[i] = mx_strdup("\0");
    for (int i = 1; n < len; i++) {
        if (mx_is_elem(uniques, str[i]) == true && i % 3 != 0) {
            uniques[n] = mx_strdup(str[i]); //uniques created
            n++;
        }
    }
    return uniques;
}
