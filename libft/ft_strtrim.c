/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erichell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 21:28:08 by erichell          #+#    #+#             */
/*   Updated: 2021/04/19 21:28:11 by erichell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_newstring(void)
{
	char	*low;

	low = malloc(sizeof(char) * 1);
	if (!low)
		return (NULL);
	ft_bzero(low, 1);
	return (low);
}

static int	ft_search_v(char const *s1, char const *set)
{
	int					i;
	int					k;
	unsigned long int	symb;

	i = 0;
	k = 0;
	symb = 0;
	while (s1[i] && set[k])
	{
		if (symb == ft_strlen(s1) - 1)
			return (0);
		while (s1[i] == set[k])
		{
			i++;
			symb++;
		}
		k = 0;
		while (s1[i] != set[k])
		{
			k++;
			if (set[k] == '\0')
				return (symb);
		}
	}
	return (symb);
}

static int	ft_search_n(char const *s1, char const *set)
{
	int					i;
	int					k;
	unsigned long int	symb;

	i = ft_strlen(s1) - 1;
	k = 0;
	symb = 0;
	while (i > 0 && symb < ft_strlen(s1) - 1 && set[k] !='\0')
	{	
		while (s1[i] == set[k] && i >= 0)
		{
			i--;
			symb++;
		}
		k = 0;
		while (s1[i] != set[k])
		{
			k++;
			if (set[k] == '\0')
				return (symb);
		}
	}
	return (symb);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		s;
	int		e;
	int		l;
	int		k;
	char	*low;

	if (!s1 || !set)
		return (NULL);
	e = ft_search_v(s1, set);
	l = ft_strlen(s1);
	if (e == l)
		return (ft_newstring());
	s = ft_search_n(s1, set);
	k = 0;
	low = (char *)malloc(sizeof(char) * ((ft_strlen(s1) + 1) - \
	(ft_search_n(s1, set) + ft_search_v(s1, set))));
	if (!low)
		return (NULL);
	while (e < (l - s))
	{
		low[k++] = s1[e++];
	}
	low[k] = '\0';
	return (low);
}
