#include "minitalk_client.h"

void	dec_conv(char sumb, int max_bit, int pid)
{
	if (max_bit > 0)
		dec_conv(sumb / 2, max_bit - 1, pid);
	if ((sumb % 2) == 1)
	{
		if (kill(pid, SIGUSR1) == -1)
			error("Error signal!\n");
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
			error("Error signal!\n");
	}
	pause();
}

void	send_mess(int pid, char *msg)
{
	int	i;

	i = 0;
	while (msg[i] != '\0')
	{
		dec_conv(msg[i], 7, pid);
		i++;
	}
}

void	my_action(int signum, siginfo_t *siginfo, void *unused)
{
	(void)unused;
	(void)siginfo;
	(void)signum;
	ft_putstr("Get signal\n");
}

int	main(int argc, char **argv)
{
	struct sigaction	action;
	int					serv_pid;

	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = my_action;
	if ((sigaction(SIGUSR2, &action, 0)) == -1)
		error("Error sigaction\n");
	if (argc != 3)
		ft_putstr("Error arguments\n");
	else
	{
		serv_pid = ft_atoi(argv[1]);
		send_mess(serv_pid, argv[2]);
	}
	return (0);
}
