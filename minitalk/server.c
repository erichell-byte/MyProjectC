#include "minitalk_server.h"

void	my_action(int signum, siginfo_t *siginfo, void *unused)
{
	static int	ascii = 0;
	static int	max_bit = 0;

	(void)unused;
	if (signum == SIGUSR1)
		ascii += 1 << (7 - max_bit);
	max_bit += 1;
	if (max_bit == 8)
	{
		ft_putchar(ascii);
		max_bit = 0;
		ascii = 0;
	}
	usleep(200);
	if (kill(siginfo->si_pid, SIGUSR2) == -1)
		error("Error signal\n");
}

int	main(int argc, char **argv)
{
	struct sigaction	action;

	(void)argv;
	if (argc != 1)
		error("Error arguments\n");
	ft_putstr("Server started!\nPID: ");
	ft_putnbr(getpid());
	ft_putstr("\n");
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = my_action;
	if ((sigaction(SIGUSR1, &action, 0)) == -1)
		error("Error sigaction\n");
	if ((sigaction(SIGUSR2, &action, 0)) == -1)
		error("Error sigaction\n");
	while (1)
		pause();
	return (0);
}
