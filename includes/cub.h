#ifndef CUB_H
# define CUB_H

# include "get_next_line.h"
//for MacOS
//# include "../minilib/mlx.h"
//for linux
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

# include "libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <errno.h>
#include <stdlib.h>

#define SCALE 16 // условный размер каждого квадратика в карте

# define ERR_MALLOC -1

# define ERR_ARGC_MIN -2
# define ERR_ARGC_MAX -3
# define ERR_ARG_SAVE -4

# define ERR_FILENAME -11
# define ERR_FILE_OPEN -12
# define ERR_FILE_ISDIR -12

# define ERR_MAP_READ -111
# define ERR_MAP_VALIDITY -112
# define ERR_MAP_RES -113
# define ERR_MAP_BAD_ARG -114
# define ERR_MAP_T -115
# define ERR_MAP_BAD -116
# define ERR_MAP_C -117
# define ERR_MAP_OPEN -118

//LINUX
# define W 119
# define S 115
# define A 97
# define D 100
# define LEFT 65361
# define RIGHT 65363
# define ESC 65307

//MAC OS
//# define W 13
//# define S 1
//# define A 0
//# define D 2
//# define LEFT 123
//# define RIGHT 124
//# define ESC 53

typedef struct	s_info
{
	int res_x;
	int res_y;

	int dup_res;

	char *no;
	char *so;
	char *we;
	char *ea;
	char *s;

	int floor_r;
	int floor_g;
	int floor_b;

	int cell_r;
	int cell_g;
	int cell_b;
	char **map;
	char **data;
	int save;
}				t_info;

typedef struct	s_win //структура для окна
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*addr;
	int			line_l;
	int			bpp;
	int			en;
}				  t_win;

typedef struct	s_point // структура для квадратика/точки
{
	int			x;
	int			y;
}				  t_point;

typedef struct	s_plr //структура для игрока и луча
{
	float		x;
	float		y;
	float		dir;
	float		start; //угол?
	float		end; //угол
}				  t_plr;

typedef struct	s_all // структура для всего вместе
{
	t_win		*wnd;
	t_plr		*plr;
	char		**map;
}				  t_all;

/*errors handle*/
void ft_error(int err_code);
/*parse cub*/
void ft_parse(t_info *info);
void ft_parse_params(t_info *info);
void ft_set_color(char *str, t_info *info, char flag);
int ft_valid_str(char *data);
char *ft_chrrep(char *str,char chr, char new_chr);
int ft_check_digit(char *line);
int ft_count_lines(char **temp);
/*debug*/
void ft_print_params(t_info *info);

#endif
