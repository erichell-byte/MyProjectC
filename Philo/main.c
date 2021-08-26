#include"philo.h"

int	print_message(int flag, t_philo *philo)
{
	pthread_mutex_lock(&philo->info->message);
	printf("%u ", get_time() - philo->info->start_time);
	if (flag != 6)
		printf("%d", philo->num + 1);
	if (flag == 1)
		printf(" take a fork\n");
	else if (flag == 2)
		printf(" is eating\n");
	else if (flag == 3)
		printf(" is sleeping\n");
	else if (flag == 4)
		printf(" is thinking\n");
	else if (flag == 5)
	{
		printf(" died\n");
		return (0);
	}
	else if (flag == 6)
	{
		printf("the number of meals is over\n");
		return (0);
	}
	pthread_mutex_unlock(&philo->info->message);
	return (0);
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (check_argum(argc, argv, &info))
		return (printf("Error\n"));
	if (philo_init(&info))
	{
		clean_mem(&info);
		return (printf("Error\n"));
	}
	if (start_pthread(&info))
	{
		clean_mem(&info);
		return (printf("Error\n"));
	}
	pthread_mutex_lock(&info.check_dead);
	pthread_mutex_unlock(&info.check_dead);
	clean_mem(&info);
	return (0);
}
