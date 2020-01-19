#include "pathfinder.h"

void print_matrix(int **matrix) {
    for (int i = 0; matrix[i] != NULL; i++) {
        for (int j = 0; matrix[i][j] != -2147483648; j++) {
            mx_printint(matrix[i][j]);
            mx_printchar(' ');
        }
        mx_printchar('\n');
    }
}
