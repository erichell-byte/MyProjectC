#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>

typedef struct s_list{
	int	width;
	int	minus;
	int	zero;
	int	precision;
	int	is_precision;
	int	star;
	int	length;
	int	for_s;
}				t_list;

int		ft_printf(const char *line, ...);
char	*ft_strdup(const char *s);
char	*ft_town(char *temp, char *finish, int i, int num);
void	ft_putstr(char *s);
void	ft_putchar(char c);
int		ft_isdigit(int num);
int		ft_atoi(const char *nptr);
size_t	ft_strlen(const char *s);
int		capac(long long int n);
int		capac_unsig(unsigned long long int n);
void	ft_putnbr(long long nb);
void	display_d (va_list arg, t_list *flags, char **start_line);
void	display_s (va_list arg, t_list *flags);
void	ft_putnbr_hex(unsigned long long nb);
int		capac_hex(unsigned long long n);
void	ft_putnbr_hex_XX(unsigned long long int nb);
void	display_p (va_list arg, t_list *flags);
void	display_s (va_list arg, t_list *flags);
void	display_proc(t_list *flags);
void	display_x (va_list arg, t_list *flags);
void	display_XX(va_list arg, t_list *flags);
void	display_c (va_list arg, t_list *flags);
void	star_flag(char **start_line, t_list *flags, va_list arg);
void	num_before_type(char **start_line, t_list *flags, va_list arg);
void	num_before_type_2(char **start_line, t_list *flags);
int		ft_zero_put(t_list *flags);
int		ft_vakum_put(t_list *flags);
int		d_no_width_yes_prec(t_list *flags, long long d);
int		d_yes_width_yes_prec_nominus(t_list *flags, long long d);
int		d_yes_width_yes_prec_yesminus(t_list *flags, long long d, \
int i, long long j);
int		d_no_width_no_prec(t_list *flags, long long d);
int		d_yes_width_no_prec_minus(t_list *flags, long long d);
int		d_yes_width_no_prec_nominus(t_list *flags, long long d, int i);
int		d_yes_width_no_prec_nozero(t_list *flags, long long d, int i);
int		d_null(t_list *flags);
int		d_precision_no(t_list *flags, long long d, int i);
int		p_prec_yes(t_list *flags, int i, unsigned long long int hex);
int		p_no_width(t_list *flags, unsigned long long int hex);
int		p_yes_width(t_list *flags, int i, unsigned long long int hex);
void	width_digit(char **start_line, t_list *flags, char digetwid[20], int i);
int		null_hex(t_list *flags);
void	width_prec_star(char **start_line, t_list *flags, va_list arg);
void	prec_minus(char **start_line, t_list *flags, char digetwid[20], int i);
void	point(char **start_line, t_list *flags);
void	width_star(char **start_line, t_list *flags, va_list arg);
void	width_prec_star_on(char digit[20], char **start_line, \
t_list *flags, int i);
int		x_hex_hull(t_list *flags);
int		x_precision(long long int hex, t_list *flags, int i);
int		x_widthon_minusoff(long long int hex, t_list *flags, int i);
int		x_widthon_minus_on(long long int hex, t_list *flags, int i);
int		x_precon_minusoff(long long int hex, t_list *flags, int i);
int		x_minusoff_precoff(long long int hex, t_list *flags, int i);
int		x_hex_hull_XX(t_list *flags);
int		x_precision_XX(long long int hex, t_list *flags, int i);
int		x_widthon_minusoff_XX(long long int hex, t_list *flags, int i);
int		x_widthon_minus_on_XX(long long int hex, t_list *flags, int i);
int		x_precon_minusoff_XX(long long int hex, t_list *flags, int i);
int		x_minusoff_precoff_XX(long long int hex, t_list *flags, int i);
int		s_precon_widthon_minusoff(char *string, size_t i, t_list *flags);
int		s_precon_widthon_minuson(char *string, size_t i, t_list *flags);
int		s_widthoff_precon(t_list *flags, size_t i, char *string);
int		s_precoff_minusoff(char *string, size_t i, t_list *flags);
int		s_precoff_minuson(char *string, size_t i, t_list *flags);

#endif