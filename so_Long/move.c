#include "so_long.h"

void	move_w(t_game *game)
{
	if (game->config.map[game->player.y - 1][game->player.x] == '0')
	{
		game->config.map[game->player.y - 1][game->player.x] = 'P';
		game->config.map[game->player.y][game->player.x] = '0';
		game->player.y -= 1;
	}
	else if (game->config.map[game->player.y - 1][game->player.x] == 'C')
	{
		game->config.map[game->player.y - 1][game->player.x] = 'P';
		game->config.map[game->player.y][game->player.x] = '0';
		game->player.y -= 1;
		game->config.collect--;
	}
	else if (game->config.map[game->player.y - 1][game->player.x] == 'E' &&
			 game->config.collect == 0)
	{
		ft_putstr("Game over, your movements is : ");
		ft_putnbr(game->config.step);
		ft_putstr("\n");
		exit(0);
	}
}

void	move_s(t_game *game)
{
	if (game->config.map[game->player.y + 1][game->player.x] == '0')
	{
		game->config.map[game->player.y + 1][game->player.x] = 'P';
		game->config.map[game->player.y][game->player.x] = '0';
		game->player.y += 1;
	}
	else if (game->config.map[game->player.y + 1][game->player.x] == 'C')
	{
		game->config.map[game->player.y + 1][game->player.x] = 'P';
		game->config.map[game->player.y][game->player.x] = '0';
		game->player.y += 1;
		game->config.collect--;
	}
	else if (game->config.map[game->player.y + 1][game->player.x] == 'E' &&
			 game->config.collect == 0)
	{
		ft_putstr("Game over, your movements is : ");
		ft_putnbr(game->config.step);
		ft_putstr("\n");
		exit(0);
	}
}

void	move_a(t_game *game)
{
	if (game->config.map[game->player.y][game->player.x - 1] == '0')
	{
		game->config.map[game->player.y][game->player.x - 1] = 'P';
		game->config.map[game->player.y][game->player.x] = '0';
		game->player.x -= 1;
	}
	else if (game->config.map[game->player.y][game->player.x - 1] == 'C')
	{
		game->config.map[game->player.y][game->player.x - 1] = 'P';
		game->config.map[game->player.y][game->player.x] = '0';
		game->player.x -= 1;
		game->config.collect--;
	}
	else if (game->config.map[game->player.y][game->player.x - 1] == 'E' &&
			 game->config.collect == 0)
	{
		ft_putstr("Game over, your movements is : ");
		ft_putnbr(game->config.step);
		ft_putstr("\n");
		exit(0);
	}
}

void 	move_d(t_game *game)
{
	if (game->config.map[game->player.y][game->player.x + 1] == '0')
	{
		game->config.map[game->player.y][game->player.x + 1] = 'P';
		game->config.map[game->player.y][game->player.x] = '0';
		game->player.x += 1;
	}
	else if (game->config.map[game->player.y][game->player.x + 1] == 'C')
	{
		game->config.map[game->player.y][game->player.x + 1] = 'P';
		game->config.map[game->player.y][game->player.x] = '0';
		game->player.x += 1;
		game->config.collect--;
	}
	else if (game->config.map[game->player.y][game->player.x + 1] == 'E' &&
			 game->config.collect == 0)
	{
		ft_putstr("Game over, your movements is : ");
		ft_putnbr(game->config.step);
		ft_putstr("\n");
		exit(0);
	}
}
