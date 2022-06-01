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

typedef struct	s_img
{
	void	*fox;
	void	*apple;
	void	*grass;
	void	*stone;
	void	*exit;
}	t_img;

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
	int	moves;
	t_img	*img;
}	t_data;

void	death_quote(void);
void	win_quote(void);
int	exit_game(t_data *data);

#endif