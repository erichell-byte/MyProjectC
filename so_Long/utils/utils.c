#include "../so_long.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			write (1, &(s[i]), 1);
			i++;
		}
	}
	return ;
}

void	error(char *str)
{
	ft_putstr(str);
	exit(0);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned long int	i;

	i = 0;
	while (i < n)
	{
		if ((unsigned char) *s1 != (unsigned char)*s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		if (*s1 == '\0' && *s2 == '\0')
			return (0);
		i++;
		s1++;
		s2++;
	}
	return (0);
}

void	set_pos(t_game *game, int x, int y)
{
	game->player.x = x;
	game->player.y = y;
}
