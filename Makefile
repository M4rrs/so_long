NAME = so_long
SRCS = *.c libft/*.c get_next_line/*.c
OBJS = *.o
INCLUDE = includes
LIB = libft
GNL = get_next_line
CCFLAGS = -Wall -Werror -Wextra
CC = gcc
FRAMEWORK = -framework OpenGL -framework AppKit





temp:
	gcc -I /usr/local/include test.c -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
