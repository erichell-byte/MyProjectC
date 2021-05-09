#include "get_next_line.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	while (size > 0)
		str[size--] = '\0';
	str[0] = '\0';
	return (str);
}

static char	*part_check(char *part, char **line)
{
	char	*p_n;
	char	*s;

	s = part;
	p_n = NULL;
	if (part)
	{	
		p_n = ft_strchr(part, '\n');
		if (p_n)
		{
			*p_n = '\0';
			*line = ft_strdup(part);
			ft_strcpy(part, ++p_n);
		}
		else
		{
			*line = ft_strdup(part);
			while (*s)
				*s++ = '\0';
		}
	}
	else
		*line = ft_strnew(1);
	return (p_n);
}

static int	ft_zero_one(int reading_byte, char **part, char *line)
{	
	if (reading_byte <= 0)
	{
		if (*part)
		{
			free(*part);
			*part = NULL;
		}
		if (reading_byte == 0)
			return (0);
		else
			return (-1);
	}
	if (reading_byte != 0 || ft_strlen(*part) || ft_strlen(line))
		return (1);
	return (0);
}

static char	*ft_p_n_part(char **p_n, char **part)
{
	char	*temp;

	temp = *p_n;
	**p_n = '\0';
	temp++;
	p_n = &temp;
	if (*part)
	{
		free(*part);
		*part = NULL;
	}
	*part = ft_strdup(*p_n);
	return (*part);
}

int	get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	int			reading_byte;
	char		*p_n;
	static char	*part;
	char		*tmp;

	reading_byte = 1;
	if (line == 0 || read(fd, buf, 0) < 0 || BUFFER_SIZE <= 0)
		return (-1);
	p_n = part_check(part, line);
	while (!p_n && reading_byte > 0)
	{
		reading_byte = read(fd, buf, BUFFER_SIZE);
		if (reading_byte <= 0)
			return (ft_zero_one(reading_byte, &part, *line));
		buf[reading_byte] = '\0';
		p_n = ft_strchr(buf, '\n');
		if (p_n)
			part = ft_p_n_part(&p_n, &part);
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		free(tmp);
	}
	return (ft_zero_one(reading_byte, &part, *line));
}

// int main()
// {
// 	char *line;
// 	int fd;
// 	int l;

// 	l = 1;
// 	fd = 0;
// 	fd = open("text.txt", O_RDONLY);
// 	while(l > 0)
// 	{
// 		l = get_next_line(fd, &line);
// 		printf("gnl=%d", l);
// 		printf("%s\n", line);
// 	}
// }
