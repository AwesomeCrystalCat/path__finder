#include "pathfinder.h"
#include <stdio.h>

int main(int argc, char **argv) {
    char **str = mx_file_to_islands(argv[1]); //str is saved and still needed for comparison
    char **uniques = mx_find_uniques(str);    //unique created
    int *numbers = mx_str_to_int(str, uniques); //indexes are added and needed to fill the matrix
    int **matrix = mx_create_matrix(numbers);
    int islands = numbers[0];
    int **predecessors = mx_init_matrix(islands);
    free(numbers);
    mx_del_strarr(&str);
    int *costs = mx_dijkstra(matrix, islands, predecessors);
    for (int i = 0; costs[i] != -2147483648; i++) {
        printf("%d\n", costs[i]);
    }
    print_matrix(predecessors);
    system("leaks -q pathfinder");
    return 0;
}
