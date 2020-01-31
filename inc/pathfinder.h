#ifndef PTHFNDR_H
#define PTHFNDR_H

#include "./libmx/inc/libmx.h"

typedef struct s_all {
    int **matrix;
    int **floyd;
    int size;
    char **uniques;
} t_all;

typedef struct s_queue {
    int *path;
    int less;
    int max;
} t_queue;

void pathfinder(char c);
char **mx_file_to_islands(const char *file);
int mx_positive_atoi(char *str);
void mx_find_uniques(char **str, t_all *total);
bool mx_is_elem(char **arr, char *str);
int mx_get_index(char *str, char **uniques);
void mx_str_to_int(char **str, t_all *total);
void print_matrix(int **matrix); //remove this function after finishing project
void mx_init_matrix(int num, t_all *ptr);
void mx_create_matrix(int *nums, t_all *ptr);
int *mx_dijkstra(int **arr, int num, int **pred, int cur);
int *mx_create_arr(int n, int val);
int **mx_floyd(int **arr, int num);

#endif
