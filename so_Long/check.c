#include "so_long.h"

int	check_first_end_wall(t_lst *buf_map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (buf_map->content[i])
	{
		if (buf_map->content[i] != '1')
			return (1);
		if (buf_map->content[i] == '1')
			i++;
	}
	while (ft_lstlast(buf_map)->content[j])
	{
		if (ft_lstlast(buf_map)->content[j] != '1')
			return (1);
		if (ft_lstlast(buf_map)->content[j] == '1')
			j++;
	}
	if (j != i)
		return (1);
	return (0);
}

int	check_side_border(t_lst *buf_map, t_game *game)
{
	int		i;
	size_t	compare;
	size_t	len;

	i = 0;
	compare = ft_strlen(buf_map->content) - 1;
	while (buf_map)
	{
		len = ft_strlen(buf_map->content) - 1;
		game->config.row++;
		if (buf_map->content[i] != '1' || buf_map->content[len] != '1' || len \
		<= 1 || compare != len)
			return (1);
		buf_map = buf_map->next;
	}
	return (0);
}

int	check_tex(t_lst *buf_map, t_game *game)
{
	int	i;

	i = 0;
	while (buf_map != NULL)
	{
		while (buf_map->content[i])
		{
			if (buf_map->content[i] == 'C')
				game->config.collect++;
			if (buf_map->content[i] == 'E')
				game->config.exit++;
			if (buf_map->content[i] == 'P')
				game->config.player++;
			i++;
		}
		buf_map = buf_map->next;
		i = 0;
	}
	if (game->config.exit == 0 || game->config.collect == 0 || \
		game->config.player > 1)
		return (1);
	return (0);
}

int	check_argum(char *start, char *end)
{
	int	i;

	i = 0;
	while (start[i] != '.')
		i++;
	if (ft_strncmp(start + i, end, 4) == 0)
		return (1);
	else
		return (0);
}
