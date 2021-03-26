#include "./includes/cub.h"


void ft_set_res(char *str, t_info *info)
{

	if (str[0] != ' ')
		ft_error(ERR_MAP_RES);
		if (info->res_x != 0 && info->res_y != 0)
			info->dup_flag = 1;
		if(ft_valid_res_str(str) && ft_num_counter(str) == 2)
		{
			ft_skip_not_num(&str);
			info->res_x = ft_atoi(str);
			ft_skip_num(&str);
			ft_skip_not_num(&str);
			info->res_y = ft_atoi(str);
			//есть строка с расширением
			info->has_param[0]++;
		}
		else
			ft_error(ERR_MAP_RES);
}

int ft_valid_color_str(char *str, t_info *info)
{
	int commas;
	int nums;

	commas =
	if (str[1] != ' ')
		ft_error(ERR_MAP_C);

}
void	ft_set_colors(char *str, t_info *info)
{
	ft_valid_color_str(str, info);
}

void ft_set_params(char *str, t_info *info)
{
	if(str[0] == 'R')
		ft_set_res(++str, info);
	else if(str[0] == 'C' || str[0] == 'F')
		ft_set_colors(str, info);
}

void ft_read_cub(int fd, t_info *info)
{
	int rd;
	char *line;

	rd = 1;

	while (rd > 0)
	{
		rd = get_next_line(fd, &line);
		if (info->dup_flag == 1)
			ft_error(ERR_MAP_D);
		/*set params*/
		if (ft_valid_str(line))
			ft_set_params(line, info);
		else
			ft_error(ERR_MAP_BAD);
		/*count map size*/
		free(line);
	}
	close(fd);
}

