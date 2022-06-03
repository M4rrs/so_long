#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include <fcntl.h>
# include <errno.h>
# include "../libft/libft.h"

#include <stdio.h>

typedef struct	s_img
{
	void	*fox;
	void	*apple;
	void	*grass;
	void	*stone;
	void	*exit;
	void	*snake;
	void	*dirt;
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
	int img_h;
	int img_w;
	int	moves;
	int frames;
	int	loop;
	int hit;
	t_img	*img;
}	t_data;
//	Frames are for the main animation loop;
//	Loop is used for enemy checking and movement;

void	return_error(t_data *data);
void initialize_data(t_data *data);

//process input
void read_error(char *line, t_data *data);
int	map_height(t_data *data, int fd);
void	process_input(t_data *data, char *file);

//validate map
int	valid_map(t_data *data);
int valid_char(t_data *data, int h, int w);
int	valid_border(t_data *data);
void	check_cep(t_data *data);

//print map + update
void	update_moves(t_data *data, int p_x, int p_y);
void	print_map(t_data *data);
void	get_images(t_data	*data);
void	print_images(t_data *data, int h, int w);
void	display_game(t_data *data);

//enemy and death
char **duplicate_map(t_data *data);
char **kill_player(char **dup, t_data *data, int h, int w);
char	**update_enemy(char	**dup, int h, int w);
void	check_enemy(t_data *data);

//animation
void	animate_player(t_data *data);

//end game
void	death_quote(void);
void	win_quote(void);
int	exit_game(t_data *data);

//helpers
int	ft_strrncmp(char *s1, char *s2, int n);
int	char_exists(t_data *data, char c);
void	free_map(t_data *data);

#endif