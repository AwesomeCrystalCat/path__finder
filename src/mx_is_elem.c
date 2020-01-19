#include "pathfinder.h"

bool mx_is_elem(char **arr, char *str) {
    for (int i = 0; arr[i] != NULL; i++) {
        if (mx_strcmp(arr[i], str) == 0)
            return false;
    }
    return true;
}
