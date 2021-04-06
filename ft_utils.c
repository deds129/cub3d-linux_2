#include "./includes/cub.h"

int ft_map_char(char c)
{
	if (c != ' ' && c != '0' && c != '1' &&
		c != '2' && c != 'N' && c != 'S'
		&& c != 'E' && c != 'W' && c != '\n'
		&& c != '\t')
		return (0);
	return (1);
}

void ft_check_params(t_info *info)
{
	int i;
	i = -1;
	while (++i < 8)
	{
		if(info->has_param[i] == 0)
			ft_error("Missing arguments\n" , info);
		if(info->has_param[i] > 1)
			ft_error("Too many arguments\n" , info);
	}
}

int ft_check_pars(t_info *info)
{
	int i;
	i = -1;
	while (++i < 8)
	{
		if(info->has_param[i] == 0 || info->has_param[i] > 1)
			return (0);
	}
	return (1);
}

