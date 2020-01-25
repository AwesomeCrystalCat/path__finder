#include "pathfinder.h"

int *mx_create_arr(int n, int val) {
    int *arr = (int *)malloc(sizeof(int) * (n + 1));

    arr[n] = -2147483648;
    for (int i = 0; arr[i] != -2147483648; i++)
        arr[i] = val;
    return arr;
}
