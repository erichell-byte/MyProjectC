#include "push_swap.h"

long long int	ft_atoi(char *nptr)
{
	int				sign;
	long long int	num;

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
	write (1, "\n", 1);
	return ;
}

void	left_less_right(int **numbers, int *right, int *left, int *pivot)
{
	while (((*numbers)[*right] >= *pivot) && (*left < *right))
		(*right)--;
	if (*left != *right)
	{
		(*numbers)[*left] = (*numbers)[*right];
		(*left)++;
	}
	while (((*numbers)[*left] <= *pivot) && (*left < *right))
		(*left)++;
	if (*left != *right)
	{
		(*numbers)[*right] = (*numbers)[*left];
		(*right)--;
	}
}

void	quicksort(int *numbers, int left, int right)
{
	int	pivot;
	int	l_hold;
	int	r_hold;

	pivot = numbers[left];
	l_hold = left;
	r_hold = right;
	while (left < right)
		left_less_right(&numbers, &right, &left, &pivot);
	numbers[left] = pivot;
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot)
		quicksort(numbers, left, pivot - 1);
	if (right > pivot)
		quicksort(numbers, pivot + 1, right);
}
