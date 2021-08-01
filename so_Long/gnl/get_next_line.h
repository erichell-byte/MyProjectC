#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include	<stdio.h>
# include	<fcntl.h>
# include	<stdlib.h>
# include	<unistd.h>
# include	<string.h>

# define BUFFER_SIZE 10

int		get_next_line(int fd, char **line);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);

#endif