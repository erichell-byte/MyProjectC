#ifndef MINITALK_CLIENT_H
# define MINITALK_CLIENT_H

# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <sys/types.h>
# include <stdlib.h>

void	ft_putchar(unsigned char c);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);
int		ft_atoi(const char *nptr);
void	error(char *str);

#endif
