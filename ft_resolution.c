#include "./includes/cub.h"


void ft_set_res(char *str, t_info *info)
{

	if (str[0] != ' ')
		ft_error(ERR_MAP_RES);
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