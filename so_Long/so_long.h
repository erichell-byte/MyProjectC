#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define KEY_W		119
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100
# define KEY_ESC	65307

//for MAC_OS
//#  define KEY_W		6
//#  define KEY_A		12
//#  define KEY_S		1
//#  define KEY_D		2
//#  define KEY_ESC		53
//# endif

# define MAP_CHARACT "01CEP"

typedef struct s_lst
{
	char			*content;
	struct s_lst	*next;
}	t_lst;

typedef struct s_pos
{
	int		x;
	int		y;
}	t_pos;

typedef struct s_config
{
	int		window_width;
	int		window_hight;
	void	*mlx_ptr;
	void	*win_ptr;
	int		collect;
	int		exit;
	char	**map;
	int		row;
	int		col;
	int		player;
	int		step;
	int		pos_x;
	int		pos_y;
	int		i;
	int		j;
	int		*screen_res_x;
	int		*screen_res_y;
}	t_config;

typedef struct s_img{
	void	*img_ptr;
	int		width;
	int		height;
}	t_img;

typedef struct s_game
{
	t_config	config;
	t_img		img;
	t_pos		player;
}	t_game;

void	ft_putstr(char *s);
void	error(char *str);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
t_lst	*t_lst_add_back(t_lst **str, char *content);
t_lst	*ft_lstlast(t_lst *lst);
int		check_first_end_wall(t_lst *buf_map);
int		check_side_border(t_lst *buf_map, t_game *game);
void	set_pos(t_game *game, int x, int y);
void	move_player(t_game *game, int keycode);
void	move_w(t_game *game);
int		exit_hook(void);
void	move_s(t_game *game);
void	move_a(t_game *game);
void	move_d(t_game *game);
void	ft_putnbr(int nb);
void	ft_putchar(char c);
void	ft_lstclear(t_lst **lst);
int		check_argum(char *start, char *end);
int		lst_buf_map(int fd, t_game *game);
int		check_tex(t_lst *buf_map, t_game *game);
int		map_at_char(t_lst *buf_map, t_game *game);
int		fill_map(t_lst *buf_map, char **map, t_game *game);
int		launch_game(t_game *game, char **map);
int		press_key(int keycode, t_game *game);
void	mlx_image_incert(t_game *game, char *way);
void	paint_game(t_game *game, char **map);

#endif
