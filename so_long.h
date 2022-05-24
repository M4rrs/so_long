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
	int	width;
	int height;
	int player_x;
	int	player_y;
	void *mlx;
	void *win;
	char **map;
}	t_data;

#endif