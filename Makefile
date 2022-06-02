NAME = so_long
SRCS = $(wildcard *.c)
OBJS = ${SRCS:.c=.o}
INCLUDE = -Iincludes -Imlx -Iget_next_line -Ilibft
LIB = -lmlx -Llibft -lft
CCFLAGS = -Wall -Werror -Wextra -fsanitize=address -g3
CC = gcc
FRAMEWORK = -framework OpenGL -framework AppKit

all: ${NAME}

${NAME} : ${OBJS} ${GNL}
	@${CC} ${CCFLAGS} ${LIB} ${INCLUDE} $(addprefix obj/, ${OBJS}) ${FRAMEWORK} -o $@

%.o : %.c
	@mkdir -p obj
	${CC} ${CCFLAGS} ${INCLUDE} -c $< -o obj/$@

clean :
	rm -rf obj

fclean : clean
	rm -rf ${NAME}
	# make fclean -C libft

re : fclean all

temp:
	gcc -I /usr/local/include test.c -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
