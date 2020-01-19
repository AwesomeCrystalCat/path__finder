#include "inc/libmx.h"

int main() {
    char *str = "5,A,B,11,A,C,10,B,D,5,C,D,6,C,E,15,D,E,4";
    char **arr = mx_strsplit(str, ',');
    for (int i = 0; arr[i]; i++) {
        mx_printstr(arr[i]);
        mx_printchar('\n');
    }
    system("leaks -q a.out");
    return 0;
}
