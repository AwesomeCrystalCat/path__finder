#include "pathfinder.h"

void mx_init_matrix(int num, t_all *ptr) {
    ptr->matrix = (int **)malloc(sizeof(int *) * (num + 1));

    ptr->matrix[ptr->size] = NULL;
    for (int i = 0; i < ptr->size; i++) {
        ptr->matrix[i] = (int *)malloc(sizeof(int) * (num + 1));
        ptr->matrix[i][ptr->size] = -2147483648;
        for (int j = 0; ptr->matrix[i][j] != -2147483648; j++) {
            if (i == j)
                ptr->matrix[i][j] = 0;
            else
                ptr->matrix[i][j] = 2147483647;
        }
    }
}
