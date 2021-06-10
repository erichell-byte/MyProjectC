#include "push_swap.h"

long long  int ft_atoi(char *nptr)
{
    int	sign;
    long long  int num;

    sign = 1;
    num = 0;
    while (*nptr == ' ' || *nptr == '\v' || *nptr == '\t' \
		|| *nptr =='\n' || *nptr == '\r' || *nptr == '\f')
        nptr++;
    if (*nptr == '-')
    {
        sign *= -1;
        nptr++;
    }
    else if (*nptr =='+')
        nptr++;
    while (*nptr >= '0' && *nptr <= '9')
    {
        num = (num * 10) + ((int)*nptr - '0');
        nptr++;
    }
    return (sign * num);
}

int	ft_isdigit(int num)
{
    if (num > 47 && num < 58)
        return (1);
    else
        return (0);
}

void	ft_putstr(char *s)
{
    int	i;

    i = 0;
    if (s)
    {
        while (s[i])
        {
            write (1, &(s[i]), 1);
            i++;
        }
    }
    write (1, "\n", 1);
    return ;
}

void quicksort(int *numbers, int left, int right)
{
    int pivot; // разрешающий элемент
    int l_hold = left; //левая граница
    int r_hold = right; // правая граница
    pivot = numbers[left];
    while (left < right) // пока границы не сомкнутся
    {
        while ((numbers[right] >= pivot) && (left < right))
            right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
        if (left != right) // если границы не сомкнулись
        {
            numbers[left] = numbers[right]; // перемещаем элемент [right] на место разрешающего
            left++; // сдвигаем левую границу вправо
        }
        while ((numbers[left] <= pivot) && (left < right))
            left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
        if (left != right) // если границы не сомкнулись
        {
            numbers[right] = numbers[left]; // перемещаем элемент [left] на место [right]
            right--; // сдвигаем правую границу вправо
        }
    }
    numbers[left] = pivot; // ставим разрешающий элемент на место
    pivot = left;
    left = l_hold;
    right = r_hold;
    if (left < pivot) // Рекурсивно вызываем сортировку для левой и правой части массива
        quicksort(numbers, left, pivot - 1);
    if (right > pivot)
        quicksort(numbers, pivot + 1, right);
}

void quesort(int *arr, int left, int right)
{
    int i = left, j = right;
    int temp, pivot = arr[ (left+right)/2 ];

    while (i <= j)
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;

        if (i <= j)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }

            i++;
            j--;
        }

    };

    if (left < j)
        quesort(arr, left, j);
    if (i < right)
        quesort(arr, i, right);
}

char	*ft_strchr(const char *s, int c)
{
    while (*s)
    {
        if (*s == (unsigned char)c)
            return ((char *)s);
        s++;
    }
    if (*s == (unsigned char)c)
        return ((char *)s);
    return (NULL);
}
