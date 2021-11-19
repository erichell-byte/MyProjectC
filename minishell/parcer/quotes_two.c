/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erichell <erichell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:39:28 by erichell          #+#    #+#             */
/*   Updated: 2021/11/18 16:05:15 by erichell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_quotes_two_cont(char *tmp, char *tmp2, char *tmp3, int *i)
{
	char	*freez;
	char	*str;

	str = ft_strjoin(tmp, tmp2);
	if (ft_strlen(str) == 0)
		*i = -1;
	else
		*i = ft_strlen(str) - 1;
	freez = str;
	str = ft_strjoin(str, tmp3);
	ft_freez(freez);
	if (ft_strlen(tmp) == 0 && ft_strlen(tmp2) == 0 && ft_strlen(tmp3) == 0)
	{	
		ft_freez(str);
		return (ft_freez_three(tmp, tmp2, tmp3, NULL));
	}
	return (ft_freez_three(tmp, tmp2, tmp3, str));
}

char	*ft_quotes_two_two_cont(char *tmp, char *tmp2, char *tmp3, int *i)
{
	char	*freez;
	char	*str;

	str = ft_strjoin(tmp, tmp2);
	*i -= 2;
	freez = str;
	str = ft_strjoin(str, tmp3);
	ft_freez(freez);
	if (ft_strlen(tmp) == 0 && ft_strlen(tmp2) == 0)
	{
		ft_freez(str);
		return (ft_freez_three(tmp, tmp2, tmp3, NULL));
	}
	return (ft_freez_three(tmp, tmp2, tmp3, str));
}

char	*ft_quotes_two(char *str, int *i, t_env **env)
{
	int		j;
	char	*tmp = NULL;
	char	*tmp2 = NULL;
	char	*tmp3 = NULL;

	j = *i;
	(*i)++;
	while (str[*i])
	{
		if (str[(*i)] == '\"')
			break ;
		if (str[*i] == '$')
			str = ft_dollar(str, i, env);
		(*i)++;
	}
	tmp = ft_substr(str, 0, j);
	tmp2 = ft_substr(str, j + 1, *i - j - 1);
	tmp3 = ft_strdup(str + *i + 1);
	if (strchr(tmp2, '|') || strchr(tmp2, '>') || strchr(tmp2, '<'))
		return (ft_freez_three(tmp, tmp2, tmp3, str));
	ft_freez(str);
	return (ft_quotes_two_cont(tmp, tmp2, tmp3, i));
}

char	*ft_quotes_two_two(char *str, int *i)
{
	int		j;
	int		k;
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	j = *i;
	k = j;
	(*i)++;
	while (str[*i])
	{
		if (str[(*i)] == '\"')
			break ;
		(*i)++;
	}
	tmp2 = ft_substr(str, j + 1, *i - j - 1);
	tmp = ft_substr(str, 0, j);
	tmp3 = ft_strdup(str + *i + 1);
	ft_freez(str);
	return (ft_quotes_two_two_cont(tmp, tmp2, tmp3, i));
}
