#include "minishell.h"
#include "libft/libft.h"

int	ft_is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

int ifkey(char c)
{
	if ( c == '_' || ft_isalnum(c))
		return (1);
	return (0);
}

int ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit (1);
}

int service_char(char s)
{
	if (s == '>' || s == '<' || s == '|' || s == '\0' || ft_is_space(s))
		return (1);
	return (0);
}
