#include "pathfinder.h"
#include <stdio.h>

//TROUBLES:
// 1. find how to fix memory leaks in mx_find_uniques function

void costs_and_pathes(int **arr, int num, int **pred, char **uni) {
    int *costs = 0;
    int *path = 0;
    int *visited = mx_create_arr(num, -1);
    int f = 0;

    for (int i = 0; i < num; i++) {
        costs = mx_dijkstra(arr, num, pred, i);
        for (int j = i + 1; costs[j] != -2147483648; j++) {
            // for (int o = 0; visited[o] != -2147483648; o++)
            //     printf("now we visited %d on j = %d\n", visited[o], j);
            if (pred[i][j] == i && visited[i] == -1) {
                printf("%s -> %s = %d\n", uni[i], uni[j], costs[j]);
            }
            else if (pred[i][j] == -1 && i != j && visited[i] == -1) {
                for (int k = 0; k < num - 1; k++) {
                    // printf("ITERATION %d step %d = %d, %d\n", i, k, num, j);
                    if (pred[k][j] != -1 && visited[k] == -1) {
                        // printf("here %d on i = %d, j = %d, k = %d\n", pred[k][j], i, j, k);
                        f = j;
                        path = mx_create_arr(num, -1);
                        while (pred[k][f] != i) {
                            if (pred[k][f]s != -1)
                               path[f] = pred[k][f];
                            f--;
                        }
                        path[f] = pred[k][f];
                        for (int cur = 0; path[cur] != -2147483648; cur++) {
                            if (path[cur] != -1)
                            printf("*%d*", path[cur]);
                        }
                        printf("\n");
                        // for (int cur = 0; path[cur] != -2147483648; cur++) {
                        //     if (path[cur] != -1)
                        //         printf("%s -> ", uni[path[cur]]);
                        // }
                        // printf("%s = %d\n", uni[j], costs[j]);
                        free(path);
                    }
                }
            }
            //     for (int k = 0; k < num; k++) {
            //         if (arr[k][j] != -1) {
            //             while (pred[k][j] != i) {
            //                 
            //                 if (arr[k][j] != -1) {
            //                     k = arr[k][j];
            //                     path[f] = arr[k][j];
            //                     f++;
            //                 }
            //                 else {
            //                     k--;
            //                 }
            //             }
            //         }
            //     }
            // }
        }
        visited[i] = 1;
    }
    free(visited);
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
    print_matrix(predecessors);

    // system("leaks -q pathfinder");
    return 0;
}

//prevoius version:
// void costs_and_pathes(int **arr, int num, int **pred, char **uni) {
//     int *costs = 0;
//     int *visited = create_arr(num, -1);

//     for (int i = 0; i < num - 1; i++) {
//         costs = mx_dijkstra(arr, num, pred, i);
//         // for (int i = 0; costs[i] != -2147483648; i++)
//         //     printf("%d\n", costs[i]);
//         // print_matrix(predecessors);
//         for (int k = 0; k < num; k++) {
//                 for (int l = 0; l < num; l++) {
//                 if (pred[k][l] != -1) {
//                     if (pred[k][l] != i)
//                     printf("%s -> ", uni[i]);
//                     if (visited[i] == -1 && visited[l] == -1)
//                         printf("%s -> %s = %d\n", uni[pred[k][l]], uni[l], costs[l]);
//                 }
//                 }
//     }
//     visited[i] = 1;
//         }
// }