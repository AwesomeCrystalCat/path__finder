#include "pathfinder.h"

int **mx_create_matrix(int *nums) {
    int **matrix = mx_init_matrix(nums[0]);
    int k = 1;

    while (nums[k] != -2147483648) {
        matrix[nums[k]][nums[k + 1]] = nums[k + 2];
        matrix[nums[k + 1]][nums[k]] = matrix[nums[k]][nums[k + 1]];
        k += 3;
    }
    return matrix;
}
