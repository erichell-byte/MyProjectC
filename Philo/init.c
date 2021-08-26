#include "philo.h"

int	philo_init(t_info *info)
{
	int	i;

	i = 0;
	info->philo = malloc(sizeof(t_philo) * info->philo_num);
	info->forks = malloc(sizeof(pthread_mutex_t) * info->philo_num);
	if (!(info->forks) || !(info->philo))
		return (1);
	while (i < info->philo_num)
	{
		info->philo[i].num = i;
		info->philo[i].left = i;
		info->philo[i].right = (i + 1) % info->philo_num;
		info->philo[i].info = info;
		info->philo[i].eat_now = 0;
		pthread_mutex_init(&info->forks[i], NULL);
		pthread_mutex_init(&info->philo[i].actions, NULL);
		pthread_mutex_init(&info->philo[i].eating, NULL);
		pthread_mutex_lock(&info->philo[i].eating);
		i++;
	}
	pthread_mutex_init(&info->message, NULL);
	pthread_mutex_init(&info->check_dead, NULL);
	pthread_mutex_lock(&info->check_dead);
	return (0);
}

int	check_argum(int argc, char **argv, t_info *info)
{
	if (argc != 5 && argc != 6)
		return (1);
	info->philo_num = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	info->forks = NULL;
	info->philo = NULL;
	if (argc == 6)
	{
		info->how_much_eat = ft_atoi(argv[5]);
		if (info->how_much_eat <= 0)
			return (1);
	}
	else
		info->how_much_eat = 0;
	if (info->philo_num <= 0 || info->time_to_die < 60 || info->time_to_eat \
	<= 0 || info->time_to_sleep < 60)
		return (1);
	return (0);
}

void	clean_mem(t_info *info)
{
	int	i;

	i = 0;
	if (info->philo)
	{
		while (i < info->philo_num)
		{
			pthread_mutex_destroy(&info->philo[i].actions);
			pthread_mutex_destroy(&info->philo[i].eating);
			i++;
		}
		i = 0;
		if (info->forks)
		{
			while (i < info->philo_num)
				pthread_mutex_destroy(&info->forks[i++]);
			free(info->forks);
			info->forks = NULL;
		}
		pthread_mutex_destroy(&info->message);
		pthread_mutex_destroy(&info->check_dead);
		free(info->philo);
		info->philo = NULL;
	}
}
