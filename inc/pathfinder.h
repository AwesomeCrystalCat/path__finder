#ifndef PTHFNDR_H
#define PTHFNDR_H

#include "./libmx/inc/libmx.h"

void pathfinder(char c);
char **mx_file_to_islands(const char *file);
int mx_positive_atoi(char *str);
char **mx_find_uniques(char **str);
bool mx_is_elem(char **arr, char *str);
int mx_get_index(char *str, char **uniques);
int *mx_str_to_int(char **str, char **uniques);
void print_matrix(int **matrix); //remove this function after finishing project
int **mx_init_matrix(int num);
int **mx_create_matrix(int *nums);
int *mx_dijkstra(int **arr, int num, int **pred, int cur);
int *mx_create_arr(int n, int val);

#endif
