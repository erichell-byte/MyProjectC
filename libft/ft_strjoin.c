/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erichell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 12:22:00 by erichell          #+#    #+#             */
/*   Updated: 2021/04/18 12:22:03 by erichell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_join(unsigned long int i, char \
*result, char const *s1, char const *s2)
{	
	int	lon;

	lon = 0;
	while (i < (ft_strlen(s1) + ft_strlen(s2)))
	{	
		while (s1[i])
		{
			result[i] = s1[i];
			i++;
		}
		while (s2[lon])
		{
			result[i] = s2[lon];
			i++;
			lon++;
		}
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char				*result;
	int					lon;
	unsigned long int	i;

	i = 0;
	lon = 0;
	if (!s1 || !s2)
		return (NULL);
	result = (char *)malloc(sizeof(*result)* \
	(ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!result)
		return (NULL);
	result = ft_join(i, result, s1, s2);
	return (result);
}
