#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	num;

	sign = 1;
	num = 0;
	while (*nptr == ' ' || *nptr == '\v' || *nptr == '\t' \
		|| *nptr =='\n' || *nptr == '\r' || *nptr == '\f')
		nptr++;
	if (*nptr == '-')
	{
		sign *= -1;
		nptr++;
	}
	else if (*nptr =='+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		num = (num * 10) + ((int)*nptr - '0');
		nptr++;
	}
	return (sign * num);
}

int	ft_isdigit(int num)
{
	if (num > 47 && num < 58)
		return (1);
	else
		return (0);
}

char	*ft_strdup(const char *s)
{
	char	*finish;
	int		i;

	i = 0;
	while (s[i])
		i++;
	finish = (char *)malloc(sizeof(char) * (i + 1));
	if (!finish)
		return (NULL);
	i = 0;
	while (s[i])
	{
		finish[i] = s[i];
		i++;
	}
	finish[i] = '\0';
	return (finish);
}

char	*ft_town(char *temp, char *finish, int i, int num)
{
	if (!finish)
		return (0);
	if (temp[0] == '-')
	{
		finish[num] = temp[0];
		num++;
	}
	while (i >= 0 && (temp[i] != '-'))
	{
		finish[num] = temp[i] + '0';
		num++;
		i--;
	}
	finish[num] = '\0';
	return (finish);
}
