#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include <fcntl.h>
# include <errno.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

typedef struct	s_data
{
	void *mlx_ptr;
	void *win_ptr;
	char **map;
	char *message;
	int	width;
	int height;
	int win_x;
	int win_y;
	int pos_x;
	int	pos_y;
//	int player;
//	int exit;
//	int items;
}	t_data;

#endif