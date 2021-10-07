#ifndef MINISHELL_H
#define MINISHELL_H

# include <stdio.h>
# include <term.h>
# include <stdlib.h>
# include <string.h>
# include "libft/libft.h"
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>

typedef struct s_env {
	char			*key;
	char			*value;
	struct s_env	*next;
} 		t_env;

typedef struct s_cmd {
	char		*cmd;
	char		**argum;
	char		**flags;
	int			flag_num;
	int 		arg_num;
	int			active;
	int 		fd_in;
	int 		fd_out;
	struct s_cmd *next;
}	t_cmd;

int g_status_error;

char	*ft_quotes_one(char *str, int *i);
char	*ft_dollar(char *str, int *i, char **env);
int		ft_is_space(char c);
char	*ft_other_dollar(char *str, int *i);
int		ifkey(char c);
t_env	*ft_lstnew_env(char *key, char *value);
void	ft_lstadd_back_env(t_env **lst, t_env *new);
void	ft_lstclear_env(t_env **lst);
int		ft_error(char *str);
int		ft_fill_env(char **env, t_env **our_env);
int		service_char(char s);
t_cmd	*ft_lstnew_cmd(char *command);
void	ft_lstadd_flags(t_cmd **cmd, char *flag);
void	ft_lstadd_argum(t_cmd **cmd, char *argm);
void	ft_lstadd_back_cmd(t_cmd **lst, t_cmd *new);

//readline
char	*readline(const char *line);
int		add_history(const char *line);
int		rl_on_new_line(void);
void	dl_redisplay(void);
void	rl_replace_line(const char *buffer, int val);

#endif
