#include "pathfinder.h"

int **mx_init_matrix(int num) {
    int **matrix = (int **)malloc(sizeof(int *) * (num + 1));

    matrix[num] = NULL;
    for (int i = 0; i < num; i++) {
        matrix[i] = (int *)malloc(sizeof(int) * (num + 1));
        matrix[i][num] = -2147483648;
        for (int j = 0; matrix[i][j] != -2147483648; j++) {
            matrix[i][j] = -1;
        }
    }
    return matrix;
}
