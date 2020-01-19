#include "pathfinder.h"

static int count_arr_len(char **str) {
    int len = 0;

    for (; str[len] != NULL; len++);
    return len;
}

int *mx_str_to_int(char **str, char **uniques) {
    int len = count_arr_len(str);
    int cur = 0;
    int *numbers = (int *)malloc(sizeof(int) * len);

    for (int i = 0; str[i] != NULL; i++) {
        if (mx_is_elem(uniques, str[i]) == false)
            numbers[cur++] = mx_get_index(str[i], uniques);
        else
            numbers[cur++] = mx_positive_atoi(str[i]);
    }
    numbers[cur] = -2147483648;
    return numbers;
}
