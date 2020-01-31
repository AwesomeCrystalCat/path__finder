#include "pathfinder.h"

void mx_create_matrix(int *nums, t_all *ptr) {
    int k = 1;

    while (nums[k] != -2147483648) {
        ptr->matrix[nums[k]][nums[k + 1]] = nums[k + 2];
        ptr->matrix[nums[k + 1]][nums[k]] = ptr->matrix[nums[k]][nums[k + 1]];
        k += 3;
    }
}
