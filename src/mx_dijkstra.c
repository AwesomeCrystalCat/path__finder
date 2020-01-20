#include "pathfinder.h"

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

int *mx_dijkstra(int **arr, int num, int **pred) {
    int *costs = create_arr(num, 2147483647);
    int *visited = create_arr(num, -1);
    int i = 0;
    int j;
    int count = 0;

    costs[0] = 0;
    while (i != -1) {
        for (j = i + 1; j < num; j++) {
            if (arr[i][j] != -1) {
                pred[i][j] = i;
                if (visited[i] == -1 && visited[j] == -1
                && arr[i][j] + costs[i] < costs[j])
                    costs[j] = costs[i] + arr[i][j];
            }
        }
        visited[i] = 1;
        i = get_min(costs, visited, costs[i]);
    }
    free(visited);
    return costs;
}