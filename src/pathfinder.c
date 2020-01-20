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

static int *create_arr(int n, int val) {
    int *arr = (int *)malloc(sizeof(int) * (n + 1));
    arr[n] = -2147483648;
    for (int i = 0; arr[i] != -2147483648; i++)
        arr[i] = val;
    return arr;
}

static int get_min(int *costs, int *visited, int c_min) {
    int min = 2147483647;
    int index = 0;

    if (checker(visited) == true) {
        for (int i = 0; costs[i] != -2147483648; i++) {
            if (visited[i] == -1 && (costs[i] < min || costs[i] < c_min)) {
                min = costs[i];
                index = i;
            }
        }
        return index;
    }
    return - 1;
}

int *mx_dijkstra(int **arr, int num) {
    int *costs = create_arr(num, 2147483647);
    int *visited = create_arr(num, -1);
    int i = 0;
    int j;
    int count = 0;

    costs[0] = 0;
    for (; i != -1;) {
        // printf("iteration - %d\n", count++ );
        for (j = 0; j < num; j++) {
            // printf("costs j%d = %d + %d\n", costs[j], costs[i], arr[i][j]);
            if (arr[i][j] != -1 && visited[i] == -1 && visited[j] == -1 && arr[i][j] + costs[i] < costs[j]) {


                        // printf("\n");
                        // printf("arr[i][j] = %d\n", arr[i][j]);
                        // printf("costs i = %d\n", costs[i]);
                        
                        
                        costs[j] = costs[i] + arr[i][j];
                        
                        

            }
        }
            visited[i] = 1;
            // for (int i = 0; visited[i] != -2147483648; i++)
            //     printf("*%d*\n", visited[i]); 
            i = get_min(costs, visited, costs[i]);
            // printf("i = %d\n", i);
            // cur = i;
    }
    return costs;
}

int main(int argc, char **argv) {
    char **str = mx_file_to_islands(argv[1]); //str is saved and still needed for comparison
    char **uniques = mx_find_uniques(str);    //unique created
    int *numbers = mx_str_to_int(str, uniques); //indexes are added and needed to fill the matrix
    int **matrix = mx_create_matrix(numbers);
    int islands = numbers[0];
    // int **parents = mx_create_matrix(numbers);
    // free(numbers);
    mx_del_strarr(&str);
    int *costs = mx_dijkstra(matrix, islands);
    for (int i = 0; costs[i] != -2147483648; i++) {
        printf("%d\n", costs[i]);
    }
    // print_matrix(matrix);
    // int *costs = mx_dijkstra(matrix, islands);
    // system("leaks -q pathfinder");
    return 0;
}
