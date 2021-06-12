#include "push_swap.h"

int	quotes_at_argv(char *argv, int *argc, int **arr_sort, int **arr)
{
	char	**num;
	int		i;

	num = NULL;
	i = 0;
	num = ft_split(argv, ' ');
	*argc = ft_argv_len(num) + 1;
	*arr = (int *)malloc(sizeof(int) * *argc + 1 );
	*arr_sort = (int *)malloc(sizeof(int) * *argc + 1);
	if (!*arr || !*arr_sort)
		return (0);
	while (i < (*argc - 1))
	{
		if (!checker_argv(*num))
			return (0);
		(*arr_sort)[i] = ft_atoi(*num);
		(*arr)[i] = (*arr_sort)[i];
		i++;
		num++;
	}
	ft_free_strok(num - i, i);
	return (1);
}

int	quotes_no_argv(char **argv, int *argc, int **arr_sort, int **arr)
{
	int	i;

	i = 0;
	*arr = (int *)malloc(sizeof(int) * *argc + 1 );
	*arr_sort = (int *)malloc(sizeof(int) * *argc + 1);
	while (i < (*argc - 1))
	{
		if (!checker_argv(*argv))
			return (0);
		(*arr_sort)[i] = ft_atoi(*argv);
		(*arr)[i] = (*arr_sort)[i];
		i++;
		argv++;
	}
	return (1);
}

int	new_lst(int *arr, int *arr_sort, int argc, t_struct **head_a)
{
	int	i;
	int	value;
	int	order;

	i = 0;
	while (i < (argc - 1))
	{
		value = arr[i];
		order = (found_at_buf(arr[i], arr_sort, argc - 1) + 1);
		new_list(head_a, order, value);
		i++;
	}
	return (i);
}

int	func_main(int **arr, int **arr_sort, int argc)
{
	int			i;
	t_main		base;
	t_struct	*head_a;
	t_struct	*head_b;

	i = 0;
	head_a = NULL;
	head_b = NULL;
	quicksort(*arr_sort, 0, argc - 2);
	if (!(checker_duplic(*arr_sort, argc - 1)) \
	|| checker_sort(*arr, *arr_sort, argc - 1))
		return (0);
	i = new_lst(*arr, *arr_sort, argc, &head_a);
	if (step_one_and_two(&head_a, &head_b, &base, i) == 0)
		return (0);
	step_three(&head_a, &head_b, &base);
	step_four(&head_a, &head_b, &base, i);
	step_five(&head_a, &head_b, &base);
	step_six(&head_a, &head_b, &base, i);
	return (0);
}

int	main(int argc, char **argv)
{
	int	*arr;
	int	*arr_sort;

	if (argc == 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	argv++;
	if (ft_strchr(*argv, ' '))
	{
		if (quotes_at_argv(*argv, &argc, &arr_sort, &arr) == 0)
			return (0);
	}
	else
		if (quotes_no_argv(argv, &argc, &arr_sort, &arr) == 0)
			return (0);
	return (func_main(&arr, &arr_sort, argc));
}
