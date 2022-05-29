#include "includes/so_long.h"

void update_moves(t_data *data)
{
	
}

int	key_hook(int key, t_data *data)
{
	update_moves(data);
	if (key == 53)
	{
		ft_putstr_fd("GAME OVER.\n", 1);
		exit_game(data);
	}
}

void	display_game(t_data *data)
{
	mlx_key_hook(data->win_ptr, key_hook, data);
	mlx_hook(data->win_ptr, 17, 1L << 17, exit_game, data);
//	mlx_loop_hook(data->mlx_ptr, render_loop, data);
	mlx_loop(data->mlx_ptr);
}