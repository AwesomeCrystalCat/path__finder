#include "pathfinder.h"
#include <stdio.h>

//TROUBLES:
// 1. find how to fix memory leaks in mx_find_uniques function

void costs_and_pathes(int **arr, int num, int **predecessors) {
    int *costs = 0;

    for (int i = 0; i < num - 1; i++) {
        costs = mx_dijkstra(arr, num, predecessors, i);
        for (int i = 0; costs[i] != -2147483648; i++)
            printf("%d\n", costs[i]);
        print_matrix(predecessors);
        
        free(costs);
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
    costs_and_pathes(matrix, islands, predecessors);
    // int *costs = mx_dijkstra(matrix, islands, predecessors, 2);
    // for (int i = 0; costs[i] != -2147483648; i++)
    //     printf("%d\n", costs[i]);
    // print_matrix(predecessors);

    system("leaks -q pathfinder");
    return 0;
}
