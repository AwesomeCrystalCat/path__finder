#include "pathfinder.h"

int mx_get_index(char *str, char **uniques) {
    int index = 0;

    while (uniques[index] != NULL) {
        if (mx_strcmp(uniques[index], str) == 0)
            return index;
        else
            index++;
    }
    return 0;
}
