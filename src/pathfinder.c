#include "pathfinder.h"
#include <stdio.h>

int main(int argc, char **argv) {
    t_all *total = malloc(sizeof(t_all));

    char **str = mx_file_to_islands(argv[1]); //str is saved and still needed for comparison
    mx_find_uniques(str, total);    //unique created
    mx_str_to_int(str, total); //indexes are added and needed to fill the matri
    print_matrix(total->matrix);
    // system("leaks -q pathfinder");
    return 0;
}
