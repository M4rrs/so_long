NAME = so_long
SRCS = *.c libft/*.c get_next_line/*.c
OBJS = ${SRCS:.c=.o}
INCLUDE = -Iincludes -Imlx -Iget_next_line -Ilibft
LIB = -lmlx 
GNL = get_next_line
CCFLAGS = -Wall -Werror -Wextra
CC = gcc
FRAMEWORK = -framework OpenGL -framework AppKit

all: ${NAME}

${NAME} :
	make re -C libft
	@${CC} ${CCFLAGS} ${LIB} ${INCLUDE} ${SRCS} ${FRAMEWORK} -o $@

clean :
	rm -f ${OBJS}

fclean : clean
	rm -rf ${NAME}
	make fclean -C libft

re : fclean all

temp:
	gcc -I /usr/local/include test.c -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
