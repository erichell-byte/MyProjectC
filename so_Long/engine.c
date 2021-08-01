#include "so_long.h"
#include "gnl/get_next_line.h"

int	press_key(int keycode, t_game *game)
{
	game->config.i = 0;
	game->config.j = 0;
	game->config.pos_x = 0;
	game->config.pos_y = 0;
	if (keycode == KEY_W)
		move_player(game, KEY_W);
	if (keycode == KEY_A)
		move_player(game, KEY_A);
	if (keycode == KEY_S)
		move_player(game, KEY_S);
	if (keycode == KEY_D)
		move_player(game, KEY_D);
	if (keycode == KEY_ESC)
		exit_hook();
	return (0);
}

void	mlx_image_incert(t_game *game, char *way)
{
	game->img.img_ptr = mlx_xpm_file_to_image(game->config.mlx_ptr, way, \
	&game->img.width, &game->img.height);
	mlx_put_image_to_window(game->config.mlx_ptr, game->config.win_ptr, \
	game->img.img_ptr, game->config.pos_x, game->config.pos_y);
	mlx_destroy_image(game->config.mlx_ptr, game->img.img_ptr);
}

void	paint_game(t_game *game, char **map)
{
	while (map[game->config.i])
	{
		while (map[game->config.i][game->config.j])
		{
			if (map[game->config.i][game->config.j] == '1')
				mlx_image_incert(game, "./data/wall.xpm");
			else if (map[game->config.i][game->config.j] == '0')
				mlx_image_incert(game, "./data/floor.xpm");
			else if (map[game->config.i][game->config.j] == 'E' && \
			game->config.collect == 0)
				mlx_image_incert(game, "./data/open_door.xpm");
			else if (map[game->config.i][game->config.j] == 'E')
				mlx_image_incert(game, "./data/close_door.xpm");
			else if (map[game->config.i][game->config.j] == 'C')
				mlx_image_incert(game, "./data/collect.xpm");
			else if (map[game->config.i][game->config.j] == 'P')
				mlx_image_incert(game, "./data/character.xpm");
			game->config.j++;
			game->config.pos_x += 32;
		}
		game->config.pos_x = 0;
		game->config.pos_y += 32;
		game->config.i++;
		game->config.j = 0;
	}
}

int	launch_game(t_game *game, char **map)
{
	int			screen_res_x;
	int			screen_res_y;

	game->config.window_hight = 32 * game->config.row;
	game->config.window_width = 32 * game->config.col;
	game->config.mlx_ptr = mlx_init();
	mlx_get_screen_size(game->config.mlx_ptr, &screen_res_x, &screen_res_y);
	if (game->config.window_hight > screen_res_y || \
	game->config.window_width > screen_res_x)
		return (1);
	game->config.win_ptr = mlx_new_window(game->config.mlx_ptr, \
	game->config.window_width, game->config.window_hight, "so_long");
	paint_game(game, map);
	mlx_hook(game->config.win_ptr, 2, 1L << 0, press_key, game);
	mlx_hook(game->config.win_ptr, 17, 0, &exit_hook, game);
	mlx_loop(game->config.mlx_ptr);
	return (0);
}
