#include "philo.h"

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	num;

	sign = 1;
	num = 0;
	while (*nptr == ' ' || *nptr == '\v' || *nptr == '\t' \
		|| *nptr == '\n' || *nptr == '\r' || *nptr == '\f')
		nptr++;
	if (*nptr == '-')
	{
		sign *= -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		num = (num * 10) + ((int)*nptr - '0');
		nptr++;
	}
	return (sign * num);
}

unsigned int	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
