#include "so_long.h"
#include "gnl/get_next_line.h"

int	lst_buf_map(int fd, t_game *game)
{
	t_lst	*buf_map;
	char	*line;

	buf_map = NULL;
	while (get_next_line(fd, &line))
	{
		t_lst_add_back(&buf_map, ft_strdup(line));
		free(line);
	}
	if (ft_strlen(line) > 0)
		t_lst_add_back(&buf_map, ft_strdup(line));
	free(line);
	if (check_first_end_wall(buf_map) || check_side_border(buf_map, game) || \
	check_tex(buf_map, game))
		return (0);
	if (map_at_char(buf_map, game))
		return (0);
	ft_lstclear(&buf_map);
	close(fd);
	return (1);
}

int	fill_map(t_lst *buf_map, char **map, t_game *game)
{
	int	i;
	int	k;

	k = 0;
	while (buf_map != NULL)
	{
		i = 0;
		map[k] = malloc(sizeof(char) * ft_strlen(buf_map->content) + 1);
		if (!map[k])
			return (1);
		while (buf_map->content[i])
		{
			if (buf_map->content[i] == 'P')
				set_pos(game, i, k);
			map[k][i] = buf_map->content[i];
			if (!ft_strchr(MAP_CHARACT, map[k][i]))
				return (1);
			i++;
		}
		map[k][i] = '\0';
		buf_map = buf_map->next;
		k++;
	}
	return (0);
}

int	map_at_char(t_lst *buf_map, t_game *game)
{
	char	**map;

	map = NULL;
	game->config.col = (int)ft_strlen(buf_map->content);
	map = malloc(sizeof(char *) * game->config.row + 1);
	if (!map)
		return (1);
	if (fill_map(buf_map, map, game))
		return (1);
	game->config.map = map;
	map = NULL;
	if (launch_game(game, game->config.map))
		return (1);
	return (0);
}
