/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erichell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 20:52:16 by erichell          #+#    #+#             */
/*   Updated: 2021/04/19 20:52:18 by erichell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned long int	i;
	char				*low;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		low = (char *)malloc(sizeof(char) * 1);
		low[0] = '\0';
		return (low);
	}
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	low = (char *)malloc(sizeof(char) * len + 1);
	if (!low)
		return (NULL);
	while (i < len)
	{
		low[i] = s[start];
		i++;
		start++;
	}
	low[i] = '\0';
	return (low);
}

// int main()
// {
// 	char *s;
// 	s = ft_substr("tripouille", 0, 42000);
// 	printf("%s", s);
// }
