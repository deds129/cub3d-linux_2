#include "./includes/cub.h"

void ft_check_params(t_info *info)
{
	int i;
	i = -1;
	while (++i < 8)
	{
		//todo: free duplicate
		if(info->has_param[i] == 0)
			ft_error("Missing arguments\n" , info);
		if(info->has_param[i] > 1)
			ft_error("Too many arguments\n" , info);
	}
}

void ft_parse_params(char *str, t_info *info)
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
}

void ft_read_cub(int fd, t_info *info)
{
	int rd;
	char *line;

	rd = 1;

	while (rd > 0)
	{
		rd = get_next_line(fd, &line);
		/*set params*/
		//todo: hasparams+ to check + muliply check
		if (ft_valid_str(line))
			ft_parse_params(line, info);
		else
			ft_error("File isn't valid\n" , info);
		/*count map size*/
		free(line);
	}
	ft_check_params(info);
	close(fd);
}

