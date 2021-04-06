#include "./includes/cub.h"

//void ft_check_max_res(t_info *info)
//{
//	mlx_get_screen_size(&info->max_res_x, &info->max_res_y);
//	printf("max res: x: %d y: %d",info->max_res_x, info->max_res_y);
//}

void ft_set_res(char *str, t_info *info)
{
	if (str[0] != ' ')
		ft_error("Bad resolution parameter\n", info);
	if(ft_valid_res_str(str) && ft_num_counter(str) == 2)
	{
		ft_skip_not_num(&str);
		info->res_x = ft_atoi(str);
		ft_skip_num(&str);
		ft_skip_not_num(&str);
		info->res_y = ft_atoi(str);
		//есть строка с расширением
		//ft_check_max_res(info);
		info->has_param[0]++;

	}
	else
		ft_error("Bad resolution parameter\n", info);
}