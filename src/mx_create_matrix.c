#include "pathfinder.h"
#include <stdio.h>

int **mx_create_matrix(int *nums) {
    int **matrix = (int **)malloc(sizeof(int *) * (nums[0] + 1));
    int k = 1;

    matrix[nums[0]] = NULL;
    for (int i = 0; i < nums[0]; i++) {
        matrix[i] = (int *)malloc(sizeof(int) * (nums[0] + 1));
        matrix[i][nums[0]] = -2147483648;
        for (int j = 0; matrix[i][j] != -2147483648; j++) {
            matrix[i][j] = -1;
        }
    }
    while (nums[k] != -2147483648) {
        // printf("%d\n", nums[k]);
        matrix[nums[k]][nums[k + 1]] = nums[k + 2];
        matrix[nums[k + 1]][nums[k]] = matrix[nums[k]][nums[k + 1]];
        k += 3;
    }
    return matrix;
}
