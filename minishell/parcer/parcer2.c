/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erichell <erichell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:13:08 by erichell          #+#    #+#             */
/*   Updated: 2021/11/18 15:19:44 by erichell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_iter_res_or_word(t_iter *iter)
{
	if (iter->res == NULL || ft_strlen(iter->res) == 0)
	{
		free(iter->word);
		iter->word = NULL;
	}
	else
	{
		free (iter->res);
		iter->res = NULL;
	}
}

int	ft_find_service(char *str)
{
	if (ft_strchr(str, '|') || ft_strchr(str, '<') || ft_strchr(str, '>'))
		return (1);
	else
		return (0);
}

int	ft_iter_cont(t_iter **iter, char **str, int i)
{
	int	j;

	j = 0;
	(*iter)->res = ft_substr((*str), 0, i + 1);
	(*iter)->full = 1;
	(*iter)->len = i + 1;
	if (!ft_strncmp_nr((*iter)->res, "export", 6))
		return (1);
	while ((*iter)->res[j])
	{
		if (ft_find_service(((*iter)->res)))
		{
			if ((*iter)->res[j] == '\'')
				(*iter)->res = ft_quotes_one_two((*iter)->res, &j);
			if ((*iter)->res[j] == '\"')
				(*iter)->res = ft_quotes_two_two((*iter)->res, &j);
		}
		j++;
	}
	return (0);
}

void	ft_parcer(char **str, t_env **our_env, t_iter **iter)
{
	int		i;

	i = 0;
	while ((*str) != NULL && (*str)[i])
	{
		if ((*str)[i] == '\'')
			(*str) = ft_quotes_one((*str), &i);
		else if ((*str)[i] == '$')
			(*str) = ft_dollar((*str), &i, our_env);
		else if ((*str)[i] == '\"')
			(*str) = ft_quotes_two((*str), &i, our_env);
		if (((*str) != NULL && ((ft_is_space((*str)[i + 1]) || \
		(*str)[i + 1] == '\0')) && (*iter)->full == 0) || \
		((*str) != NULL && (only_service((*str)[i + 1])) \
		&& (*iter)->full == 0 && ((*str)[i] != '\'' && (*str)[i] != '\"')))
		{
			if (ft_iter_cont(iter, str, i))
				return ;
		}
		if ((*str) == NULL)
			return ;
		i++;
	}
}

void	ft_find_flags(char *str, t_cmd *new, t_iter *iter, int *i)
{
	int	j;

	while (str[*i] == '-' && !service_char(str[(*i) + 1]))
	{
		j = (*i);
		while (!service_char(str[(*i)]))
			(*i)++;
		iter->flags = ft_substr(str, j, (*i) - j);
		ft_lstadd_flags(&new, iter->flags);
		free(iter->flags);
		iter->flags = NULL;
		while (ft_is_space(str[(*i)]) && str[(*i)] != '\0')
			(*i)++;
	}
}
