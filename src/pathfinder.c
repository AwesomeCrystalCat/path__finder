#include "pathfinder.h"
#include <stdio.h>

//TROUBLES:
// 1. find how to fix memory leaks in mx_find_uniques function

static int *create_arr(int n, int val) {
    int *arr = (int *)malloc(sizeof(int) * (n + 1));

    arr[n] = -2147483648;
    for (int i = 0; arr[i] != -2147483648; i++)
        arr[i] = val;
    return arr;
}

void costs_and_pathes(int **arr, int num, int **pred, char **uni) {
    int *costs = 0;
    int *visited = create_arr(num, -1);

    for (int i = 0; i < num - 1; i++) {
        costs = mx_dijkstra(arr, num, pred, i);
        // for (int i = 0; costs[i] != -2147483648; i++)
        //     printf("%d\n", costs[i]);
        // print_matrix(predecessors);
        for (int k = 0; k < num; k++) {
                for (int l = k + 1; l < num; l++) {
                if (pred[k][l] != -1) {
                    if (pred[k][l] != i)
                    printf("%s -> ", uni[i]);
                    if (visited[i] == -1 && visited[l] == -1)
                        printf("%s -> %s = %d\n", uni[pred[k][l]], uni[l], costs[l]);
                }
                }
    }
    visited[i] = 1;
        }
}

int main(int argc, char **argv) {
    char **str = mx_file_to_islands(argv[1]); //str is saved and still needed for comparison
    char **uniques = mx_find_uniques(str);    //unique created
    int *numbers = mx_str_to_int(str, uniques); //indexes are added and needed to fill the matrix
    int **matrix = mx_create_matrix(numbers);
    int islands = numbers[0];
    int **predecessors = mx_init_matrix(islands);
    free(numbers);
    mx_del_strarr(&str);
    costs_and_pathes(matrix, islands, predecessors, uniques);
    // int *costs = mx_dijkstra(matrix, islands, predecessors, 2);
    // for (int i = 0; costs[i] != -2147483648; i++)
    //     printf("%d\n", costs[i]);
    // print_matrix(predecessors);

    // system("leaks -q pathfinder");
    return 0;
}
