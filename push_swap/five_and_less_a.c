#include "push_swap.h"

void	three_elem_a(t_struct **head_a)
{
	if (ft_lstlast(*head_a)->order > (*head_a)->order && ft_lstlast(*head_a)->order \
	> (*head_a)->next->order && (*head_a)->order > (*head_a)->next->order)
		sa(head_a);
	else if ((*head_a)->order > (*head_a)->next->order && (*head_a)->order >\
	ft_lstlast (*head_a)->order && (*head_a)->next->order \
	> ft_lstlast(*head_a)->order)
	{
		sa(head_a);
		rra(head_a);
	}
	else if ((*head_a)->order > (*head_a)->next->order && (*head_a)->order > \
	ft_lstlast(*head_a)->order && ft_lstlast(*head_a)->order > \
	(*head_a)->next->order)
		ra(head_a);
	else if ((*head_a)->next->order > (*head_a)->order && (*head_a)->next->order > \
	ft_lstlast(*head_a)->order && ft_lstlast(*head_a)->order > (*head_a)->order)
	{
		sa(head_a);
		ra(head_a);
	}
	else if ((*head_a)->next->order > (*head_a)->order && (*head_a)->next->order > \
	ft_lstlast(*head_a)->order && (*head_a)->order > ft_lstlast(*head_a)->order)
		rra(head_a);
}

static void	four_elem_a(t_struct **head_a, t_struct **head_b, t_main *base)
{
	while ((*head_a)->order != base->next)
		ra(head_a);
	pb(head_a, head_b);
	three_elem_a(head_a);
	pa(head_b, head_a, *base);
}

int	five_and_less_a(t_struct **head_a, t_struct **head_b, t_main *base)
{
	if (ft_lstsize(*head_a) <= 5)
	{
		if (ft_lstsize(*head_a) == 2)
		{
			if ((*head_a)->order > (*head_a)->next->order)
				sa(head_a);
		}
		else if (ft_lstsize(*head_a) == 3)
			three_elem_a(head_a);
		else if (ft_lstsize(*head_a) == 4 )
			four_elem_a(head_a, head_b, base);
		else if (ft_lstsize(*head_a) == 5)
		{
			while ((*head_a)->order != base->next)
				ra(head_a);
			base->next++;
			pb(head_a, head_b);
			four_elem_a(head_a, head_b, base);
			pa(head_b, head_a, *base);
		}
		return (1);
	}
	else
		return (0);
}
