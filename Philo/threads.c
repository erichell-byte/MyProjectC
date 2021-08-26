#include "philo.h"

int	start_pthread(t_info *info)
{
	int			i;
	pthread_t	thread_id;
	t_philo		*philo;

	i = 0;
	info->start_time = get_time();
	if (info->how_much_eat > 0)
	{
		if (pthread_create(&thread_id, NULL, &how_meals, info))
			return (1);
		pthread_detach(thread_id);
	}
	while (i < info->philo_num)
	{
		philo = &info->philo[i];
		if (pthread_create(&thread_id, NULL, &life, philo))
			return (1);
		pthread_detach(thread_id);
		usleep(100);
		i++;
	}
	return (0);
}

void	*how_meals(void *info_r)
{
	int		i;
	int		eat;
	t_info	*info;

	eat = 0;
	info = info_r;
	while (eat < info->how_much_eat)
	{
		i = 0;
		while (i < info->philo_num)
			pthread_mutex_lock(&info->philo[i++].eating);
		eat++;
	}
	print_message(6, &info->philo[0]);
	pthread_mutex_unlock(&info->check_dead);
	return (0);
}

void	*life(void *philo_r)
{
	t_philo		*philo;
	pthread_t	thread_id;

	philo = philo_r;
	philo->eat_start = get_time();
	philo->time_limit = philo->eat_start + philo->info->time_to_die;
	pthread_create(&thread_id, NULL, &check_dead, philo_r);
	pthread_detach(thread_id);
	while (1)
	{
		do_eat(philo);
		do_sleep(philo);
		print_message(4, philo);
	}
}

void	*check_dead(void *philo_r)
{
	t_philo	*philo;

	philo = philo_r;
	while (1)
	{
		pthread_mutex_lock(&philo->actions);
		if (!(philo->eat_now) && get_time() > philo->time_limit)
		{
			print_message(5, philo);
			pthread_mutex_unlock(&philo->actions);
			pthread_mutex_unlock(&philo->info->check_dead);
			return ((void *)0);
		}
		pthread_mutex_unlock(&philo->actions);
		usleep(1000);
	}
}
