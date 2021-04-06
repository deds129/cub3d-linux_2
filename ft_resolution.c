#include "./includes/cub.h"

void ft_check_max_res(t_info *info)
{
	mlx_get_screen_size(&info->max_res_x, &info->max_res_y);
	if (info->max_res_x < info->res_x)
		info->res_x = info->max_res_x;
	if (info->max_res_y < info->res_y)
		info->res_y = info->max_res_y;
}

void ft_set_res(char *str, t_info *info)
{
	mlx_get_screen_size(&info->max_res_x, &info->max_res_y);
	if (str[0] != ' ')
		ft_error("Bad resolution parameter\n", info);
	if(ft_valid_res_str(str) && ft_num_counter(str) == 2)
	{
		ft_skip_not_num(&str);
		info->res_x = ft_atoi(str);
		if (info->res_x < 0 || info->res_x > 2147483647)
			info->res_x = info->max_res_x;
		ft_skip_num(&str);
		ft_skip_not_num(&str);
		info->res_y = ft_atoi(str);
		if (info->res_y < 0 || info->res_y > 2147483647)
			info->res_y = info->max_res_y;
		ft_check_max_res(info);
		info->has_param[0]++;
	}
	else
		ft_error("Bad resolution parameter\n", info);
}