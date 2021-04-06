#ifndef CUB_H
# define CUB_H

# include "get_next_line.h"

//for MacOS
# include "../minilibx_mac/mlx.h"
//# include "../minilibx_mac/mlx_int.h"

//for linux
//# include "../minilibx-linux/mlx.h"
//# include "../minilibx-linux/mlx_int.h"

# include "libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <errno.h>
#include <stdlib.h>

#define SCALE 16 // условный размер каждого квадратика в карте



//LINUX
//# define W 119
//# define S 115
//# define A 97
//# define D 100
//# define LEFT 65361
//# define RIGHT 65363
//# define ESC 65307

//MAC OS
# define W 13
# define S 1
# define A 0
# define D 2
# define LEFT 123
# define RIGHT 124
# define ESC 53

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
	float		start;
	float		end;
}				  t_plr;

typedef struct	s_info
{
	int res_x; //0
	int res_y; //0
	int has_param[8];

	char *no; //1
	char *so;  //2
	char *we; //3
	char *ea; //4
	char *s; //5

	int floor; //6

	int cell; //7
	char **map;
	int iline_num;
	int iline_size;
	int save;
	int map_start;
	char *filename;
	t_win swin;
	t_plr splr;
}				t_info;





/*errors handle*/
//void ft_error(int err_code);
void ft_error(char *err_msg, t_info *info);

/*read tier*/
void ft_read_cub(int fd, t_info *info);

/*parse tier*/
int ft_valid_str(char *str);
int ft_valid_res_str(char *line);
int	ft_num_counter(char *str);
void ft_skip_not_num(char **str);
void ft_skip_num(char **str);
int	ft_commas_num(char *str);
int	ft_spaces_num(char *str);
unsigned long	ft_color_to_hex(int red, int green, int blue);
int			ft_skip_spaces(char *str);
void ft_check_params(t_info *info);
int ft_map_bits(char *line);
void ft_map_params(char *line, t_info *info);
int ft_check_pars(t_info *info);
void ft_parse_map(t_info *info);
int ft_map_char(char c);

/*res*/
void ft_set_res(char *str, t_info *info);
void	ft_set_colors(char *str, t_info *info);

/*color*/

/*texture*/
void ft_set_textures(char *str, t_info *info);

/*free*/
void ft_free_all(t_info *info);



/*mlx tier*/
void            pixel_put(t_win *wnd, int x, int y, int color);

/*game start*/
void ft_launch_game(t_info *info);


/*debug*/
void ft_print_params(t_info *info);



#endif
