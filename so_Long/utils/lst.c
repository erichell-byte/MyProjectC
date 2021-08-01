#include "../so_long.h"

t_lst	*t_lst_add_back(t_lst **str, char *content)
{
	t_lst	*first;
	t_lst	*new;

	if (!content)
		return (NULL);
	new = malloc(sizeof(t_lst));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	if (!*str)
		*str = new;
	else
	{
		first = *str;
		while ((*str)->next)
			*str = (*str)->next;
		(*str)->next = new;
		*str = first;
	}
	return (new);
}

t_lst	*ft_lstlast(t_lst *lst)
{
	if (lst)
	{
		while (lst->next != NULL)
			lst = lst->next;
	}
	return (lst);
}

void	ft_lstclear(t_lst **lst)
{
	t_lst	*low;
	t_lst	*step;

	low = *lst;
	if (lst && (*lst))
	{
		while (low)
		{
			step = low->next;
			free(low);
			low = step;
		}
	}
	*lst = NULL;
}
