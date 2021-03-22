#include "./includes/cub.h"

void ft_set_color(char *str, t_info *info, char flag)
{
	char **tmp;
	int i;
	char *new_str;
	i = 0;
	tmp = NULL;
	new_str = NULL;
	if (!(new_str = ft_chrrep(str,',',' ')))
		ft_error(ERR_MALLOC);
	//printf("%s\n", new_str);
	if (!(tmp = ft_split(new_str, ' ')))
		ft_error(ERR_MALLOC);
	if (ft_count_lines(tmp) == 4 && ft_check_digit(tmp[1]) &&
		ft_check_digit(tmp[2]) && ft_check_digit(tmp[3]))
	{
		if (flag == 'F')
		{
			info->floor_r = ft_atoi(tmp[1]);
			info->floor_g = ft_atoi(tmp[2]);
			info->floor_b = ft_atoi(tmp[3]);
		}
		else if (flag == 'C')
		{
			info->cell_r = ft_atoi(tmp[1]);
			info->cell_g = ft_atoi(tmp[2]);
			info->cell_b = ft_atoi(tmp[3]);
		}
	}
	else
		ft_error(ERR_MAP_C);
	free(tmp);
	free(new_str);
}

void ft_set_resolution(char *str, t_info *info)
{
	char **tmp;
	int i;

	i = 0;
	tmp = NULL;
	if(str[1] != ' ')
		ft_error(ERR_MAP_RES);

	if (!(tmp = ft_split(str, ' ')))
		ft_error(ERR_MALLOC);
	if (ft_count_lines(tmp) == 3 &&  ft_check_digit(tmp[1]) &&
		ft_check_digit(tmp[2]) )
	{
		info->res_x = ft_atoi(tmp[1]);
		info->res_y = ft_atoi(tmp[2]);
	}
	//todo: max resolution case
	else
		ft_error(ERR_MAP_RES);
	free(tmp);
}

void ft_parse_params(t_info *info) //int map_size
{
	int i;
	i = -1;
	while (info->data[++i])
	{
		if (ft_valid_str(info->data[i]) == 1)
		{
			if (info->data[i][0] == 'R' )
				ft_set_resolution(info->data[i], info);
		}
		else
			ft_error(ERR_MAP_VALIDITY);

	}
}

void ft_parse(t_info *info)
{
	ft_parse_params(info);
	ft_print_params(info);
}

