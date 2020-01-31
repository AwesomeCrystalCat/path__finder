#include "pathfinder.h"

static bool is_unique(char **arr, char *str, int len) {
    for (int i = 0; i < len; i++) {
        if (mx_strcmp(arr[i], str) == 0)
            return false;
    }
    return true;
}

void mx_find_uniques(char **str, t_all *total) {
    int len = mx_positive_atoi(str[0]);
    int n = 0;
    total->uniques = (char **)malloc(sizeof(char *) * (len + 1));

    total->uniques[len] = NULL;
    total->uniques[n] = mx_strdup(str[1]);
    n++;
    for (int i = 2; str[i] != '\0'; i++) {
        if (is_unique(total->uniques, str[i], n) == true
        && i % 3 != 0) {
        total->uniques[n] = mx_strdup(str[i]);
        n++;
        }
    }
}
