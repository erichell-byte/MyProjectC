#include "push_swap.h"

void back_to_stek_a(t_struct **head_a,t_struct **head_b, t_main *base)
{
    while (found_mid_and_more(*head_b, base))
    {
		if (ft_lstsize(*head_b) <= 5)
            five_and_less_b(head_b, head_a, base);
        if ((*head_b)->order == base->next)
        {
            pa(head_b, head_a, *base);
            ra(head_a);
            base->next++;
        }
        else if ((*head_b)->order >= base->mid)
            pa(head_b, head_a, *base);
        else if ((*head_b)->order < base->mid && (*head_b) != NULL)
        {
            if (found_best_way_start_big((*head_b), base) <= found_best_way_end_big((*head_b), base) && found_mid_and_more(*head_b, base))
            {
                if (found_best_way_start_big((*head_b), base) == 2)
                    sb(head_b);
                else if ((*head_b)->order < base->mid && (*head_b) != NULL)
                    rb(head_b);
                else if ((*head_b)->order >= base->mid)
                    pa(head_b, head_a, *base);
            }
            else if (found_best_way_start_big((*head_b), base) > found_best_way_end_big((*head_b), base) && found_mid_and_more(*head_b, base))
            {
                rrb(head_b);
                if ((*head_b)->order >= base->mid)
                    pa(head_b, head_a, *base);
            }
        }
    }
}

void sort_at_stek_b(t_struct **head_a,t_struct **head_b, t_main *base)
{
    if ((*head_b)->order == base->next)
    {
        pa(head_b, head_a, *base);
        ra(head_a);
        base->next++;
    }
    else if ((*head_b)->next->order == base->next)
    {
        sb(head_b);
        pa(head_b, head_a, *base);
        ra(head_a);
        base->next++;
    }
    else if (found_next_start(*head_b, base) <= found_next_end(*head_b, base))
    {
        while ((*head_b)->order != base->next)
            rb(head_b);
        pa(head_b, head_a, *base);
        ra(head_a);
        base->next++;

    }
    else if ((found_next_start(*head_b, base) > found_next_end(*head_b, base)))
    {
        while (ft_lstlast(*head_b)->order != base->next)
            rrb(head_b);
        rrb(head_b);
        pa(head_b, head_a, *base);
        ra(head_a);
        base->next++;
    }
}

int quotes_at_argv(char *argv, int *argc, int **arr_sort, int  **arr)
{
    char **num = NULL;
    int i ;

    i = 0;
    num = ft_split(argv, ' ');
    *argc = ft_argv_len(num) + 1;
    *arr = (int *)malloc(sizeof(int) * *argc + 1 );
    *arr_sort = (int *)malloc(sizeof(int) * *argc + 1);
    while (i < (*argc - 1))
    {
        if (!checker_argv(*num))
            return(0);
        (*arr_sort)[i] = ft_atoi(*num);
        (*arr)[i] = (*arr_sort)[i];
        i++;
        num++;
    }
    return (1);
}

int quotes_no_argv(char **argv, int *argc, int **arr_sort, int  **arr)
{
    int i;

    i = 0;
    *arr = (int *)malloc(sizeof(int) * *argc + 1 );
    *arr_sort = (int *)malloc(sizeof(int) * *argc + 1);
    while (i < (*argc - 1))
    {
        if (!checker_argv(*argv))
            return(0);
        (*arr_sort)[i] = ft_atoi(*argv);
        (*arr)[i] = (*arr_sort)[i];

        i++;
        argv++;
    }
    return(1);
}

int new_lst(int *arr, int *arr_sort, int argc, t_struct **head_a)
{
    int i;
    int value;
    int order;

    i = 0;
    while (i < (argc - 1)) // создание односвязного списка
    {
        value = arr[i];
        order = (found_at_buf(arr[i], arr_sort, argc - 1) + 1);
        new_list(head_a, order, value);
        i++;
    }
    return (i);
}
int main(int argc, char **argv)
{
    int i;
    int *arr;
    int *arr_sort;
    t_main base;
	t_struct *head_a = NULL;
    t_struct *head_b = NULL;

    if (argc == 1)
        write(1, "\n", 1);
    argv++;
    if (ft_strchr(*argv, ' '))
    {
        if (quotes_at_argv(*argv, &argc, &arr_sort, &arr) == 0)
            return (0);
    }
    else
        if (quotes_no_argv(argv, &argc, &arr_sort, &arr) == 0)
            return (0);
    quicksort(arr_sort, 0, argc - 2);
    if (!(checker_duplic(arr_sort, argc - 1)) || checker_sort(arr, arr_sort, argc - 1))
        return (0);
    i = new_lst(arr, arr_sort, argc, &head_a);
    if (step_one_and_two(&head_a, &head_b, &base, i) == 0)
        return(0);
    step_three(&head_a, &head_b, &base);
    step_four(&head_a, &head_b, &base, i);
    step_five(&head_a, &head_b, &base);
    step_six(&head_a, &head_b, &base);

    while(head_a != NULL)
    {
        printf("%d ", head_a->value);
        head_a = head_a->next;
    }
    printf("|stek a|");
    printf("\n");
    printf("\n");
    while(head_b != NULL)
    {
        printf("%d ", head_b->value);
        head_b = head_b->next;
    }
    printf("|stek b|");
    return(0);
}