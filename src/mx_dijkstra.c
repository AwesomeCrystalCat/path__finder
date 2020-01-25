#include "pathfinder.h"
#include <stdio.h>

static bool checker(int *visited) {
    int count = 0;

    for (int i = 0; visited[i] != -2147483648; i++) {
        if (visited[i] == -1)
            count++;
    }
    return count == 0 ? false : true;
}

static int get_min(int *costs, int *visited, int c_min) {
    int min = 2147483647;
    int index = 0;

    if (checker(visited) == true) {
        for (int i = 0; costs[i] != -2147483648; i++) {
            if (visited[i] == -1 && (costs[i] < min
                || costs[i] < c_min)) {
                min = costs[i];
                index = i;
            }
        }
        return index;
    }
    return - 1;
}

int *mx_dijkstra(int **arr, int num, int **pred, int cur) { //add one more veriable
    int *costs = mx_create_arr(num, 2147483647);
    int *visited = mx_create_arr(num, -1);
    int i = cur;
    int j = 0;
    int k = 0;
    i = 0;

    costs[i] = 0;
    while (i != -1) {
        for (j = i + 1; j < num; j++) {
            if (arr[i][j] != -1 && arr[i][j] + costs[i] < costs[j]) {
                for (k = 0; k < i; k++)
                    pred[k][j] = -1;
                    pred[j][k] = pred[k][j];
            }
            if (arr[i][j] != -1) {
                pred[i][j] = i;
                pred[j][i] = pred[i][j];
            }
            if (arr[i][j] != -1 && visited[i] == -1 && visited[j] == -1
                && arr[i][j] + costs[i] <= costs[j]) {
                // pred[i][j] = i;
                costs[j] = costs[i] + arr[i][j];
            }
        }
        visited[i] = 1;
        i = get_min(costs, visited, costs[i]);
    }
    free(visited);
    return costs;
}
            //B = 11, 0, 11, 5, 9
            //C = 10, 11, 0, 5, 9 
            //D = 16, 5, 6, 0, 4
            //E = 20, 9, 10, 
            //

//probably you gonna need this function, if it will work properly
//void **build_preds() {
//     for (int l = i + 1; l < num; l++) {
//             if (arr[i][l] != -1 && arr[i][l] + costs[l] < costs[l]) {
//                 for (k = 0; k < i; k++)
//                     pred[k][l] = -1;
//             }
//             if (arr[i][l] != -1) {
//                 pred[i][l] = i;
//                 pred[l][i] = pred[i][l];
//             }
//         }
// }
