#include "push_swap.h"

void	first_corr_stek(t_struct **head_a, t_struct **head_b, t_main *base)
{
	while (found_mid_and_less(*head_a, base))
	{
		if ((*head_a)->order <= base->mid)
			pb(head_a, head_b);
		else if ((*head_a)->order > base->mid && (*head_a) != NULL)
		{
			if (found_best_way_start_low((*head_a), base) <= \
			found_best_way_end_low((*head_a), base) && \
			found_mid_and_less(*head_a, base))
			{
				while ((*head_a)->order > base->mid && (*head_a) != NULL)
					ra(head_a);
				if ((*head_a)->order <= base->mid)
					pb(head_a, head_b);
			}
			else if (found_best_way_start_low((*head_a), base) > \
			found_best_way_end_low((*head_a), base) && \
			found_mid_and_less(*head_a, base))
			{
				rra(head_a);
				if ((*head_a)->order <= base->mid)
					pb(head_a, head_b);
			}
		}
	}
}

int	step_one_and_two(t_struct **head_a, t_struct **head_b, t_main *base, int i)
{
	base->next = 1;
	base->max = i;
	base->mid = (base->max / 2) + base->next;
	base->flag = 0;
	if (five_and_less_a(head_a, head_b, base))
		return (0);
	first_corr_stek(head_a, head_b, base);
	while (*head_b != NULL)
	{
		base->max = (base)->mid;
		base->mid = (((base)->max - (base)->next) / 2) + (base)->next;
		base->flag++;
		back_to_stek_a(head_a, head_b, base);
	}
	return (1);
}
