#include "pathfinder.h"

int **mx_floyd(int **arr, int num) {
    int **floyd = arr;

    for (int k = 0; k < num; k++) {
        for (int i = 0; i < num; i++) {
            for (int j = 0; j < num; j++) {
                if (floyd[i][k] + floyd[k][j] < floyd[i][j]
                && floyd[i][k] + floyd[k][j] > 0)
                    floyd[i][j] = floyd[i][k] + floyd[k][j];
            }
        }
    }
    return floyd;
}
