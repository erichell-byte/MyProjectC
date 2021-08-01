#include "so_long.h"
#include "gnl/get_next_line.h"

int	exit_hook(void)
{
	ft_putstr("Exit game\n");
	exit(0);
}

void	init_config(t_game *game)
{
	game->config.col = 0;
	game->config.row = 0;
	game->config.win_ptr = NULL;
	game->config.mlx_ptr = NULL;
	game->config.exit = 0;
	game->config.collect = 0;
	game->config.player = 0;
	game->config.exit = 0;
	game->config.map = 0;
	game->config.window_width = 0;
	game->config.window_hight = 0;
	game->config.step = 0;
	game->config.pos_x = 0;
	game->config.pos_y = 0;
	game->config.i = 0;
	game->config.j = 0;
}

void	move_player(t_game *game, int keycode)
{
	t_pos	temp;

	temp.y = game->player.y;
	temp.x = game->player.x;
	if (keycode == KEY_W && game->config.map[game->player.y - 1][game->player \
	.x] != '1')
		move_w(game);
	else if ((keycode == KEY_S && game->config.map[game->player.y \
	+ 1][game->player.x] != '1'))
		move_s(game);
	else if ((keycode == KEY_A && game->config.map[game->player \
	.y][game->player.x - 1] != '1'))
		move_a(game);
	else if ((keycode == KEY_D && game->config.map[game->player \
			.y][game->player.x + 1] != '1'))
		move_d(game);
	if (temp.y != game->player.y || temp.x != game->player.x)
	{
		game->config.step++;
		ft_putstr("Movements : ");
		ft_putnbr(game->config.step);
		ft_putstr("\n");
	}
	paint_game(game, game->config.map);
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		fd;

	init_config(&game);
	if (argc < 2 || argc > 2)
		error("Error numbers of arguments\n");
	if (!check_argum(argv[1], ".ber"))
		error("Error format file of map\n");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error("Wrong format of file\n");
	if (!lst_buf_map(fd, &game))
		error("Error components of map\n");
	return (0);
}
