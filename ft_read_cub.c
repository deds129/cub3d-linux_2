#include "./includes/cub.h"

void ft_parse_params(char *str, char *tmp, t_info *info)
{
	if(str[0] == 'R')
		ft_set_res(++str, info);
	else if(str[0] == 'C' || str[0] == 'F')
		ft_set_colors(str, info);
	else if((str[0] == 'N' && str[1] == 'O') ||
			(str[0] == 'W' && str[1] == 'E') ||
			(str[0] == 'E' && str[1] == 'A') ||
			(str[0] == 'S')
			)
		ft_set_textures(str, info);
	else if (ft_map_bits(tmp) == 1 && info->map_start == 0)
	{
		if (ft_check_pars(info) == 0)
			ft_error("Map must be after parameters\n",info);
		//находим количество строк и самую длинную строку
		ft_map_params(tmp, info);
	}
}

void ft_read_cub(int fd, t_info *info)
{
	int rd;
	char *line;
	char *tmp;

	rd = 1;
	while (rd > 0)
	{
		rd = get_next_line(fd, &line);
		tmp = line;
		line += ft_skip_spaces(line);
		if (ft_valid_str(tmp))
			ft_parse_params(line,tmp, info);
		else
			ft_error("File isn't valid\n" , info);
		/*count map size*/
		free(tmp);
	}
	ft_check_params(info);
	//todo: заполняем карту и проверяем валидность
	ft_parse_map(info);
	ft_launch_game(info);
	close(fd);
}

