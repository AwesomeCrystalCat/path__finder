NAME = pathfinder

LIB = ./libmx/libmx.a

INC = ./inc/pathfinder.h

HEAD = pathfinder.h

SRCS = ./src/pathfinder.c \
		./src/mx_file_to_islands.c \
		./src/mx_positive_atoi.c \
		./src/mx_find_uniques.c \
		./src/mx_is_elem.c \
		./src/mx_get_index.c \
		./src/mx_str_to_int.c \
		./src/print_matrix.c \
		./src/mx_create_matrix.c \
		./src/mx_init_matrix.c \
		./src/mx_dijkstra.c \

SRCOUT = pathfinder.c \
		mx_file_to_islands.c \
		mx_positive_atoi.c \
		mx_find_uniques.c \
		mx_is_elem.c \
		mx_get_index.c \
		mx_str_to_int.c \
		print_matrix.c \
		mx_create_matrix.c \
		mx_init_matrix.c \
		mx_dijkstra.c \

OBJS = ./obj/pathfinder.o \
		./obj/mx_file_to_islands.o \
		./obj/mx_positive_atoi.o \
		./obj/mx_find_uniques.o \
		./obj/mx_is_elem.o \
		./obj/mx_get_index.o \
		./obj/mx_str_to_int.o \
		./obj/print_matrix.o \
		./obj/mx_create_matrix.o \
		./obj/mx_init_matrix.o \
		./obj/mx_dijkstra.o \

OBJOUT = pathfinder.o \
		mx_file_to_islands.o \
		mx_positive_atoi.o \
		mx_find_uniques.o \
		mx_is_elem.o \
		mx_get_index.o \
		mx_str_to_int.o \
		print_matrix.o \
		mx_create_matrix.o \
		mx_init_matrix.o \
		mx_dijkstra.o \

CFLAG = -std=c11 -Wall -Wextra -Wpedantic -Werror

all: install clean

install:
	@make install -C libmx
	@cp $(SRCS) .
	@cp $(INC) .
	@clang $(CFLAGS) -c $(SRCOUT) -I $(HEAD)
	@clang $(CFLAGS) $(LIB) $(OBJOUT) -o $(NAME)
	@mkdir -p obj
	@mv $(OBJOUT) ./obj

clean:
	@rm -rf $(OBJOUT) $(SRCOUT) $(HEAD) obj
	@make uninstall -C libmx

uninstall: clean
	@make clean -C libmx
	@rm -rf $(NAME)

reinstall: uninstall all