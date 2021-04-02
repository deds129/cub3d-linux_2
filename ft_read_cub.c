#include "./includes/cub.h"



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

void ft_map_params(char *line, t_info *info)
{
	int i;
	i = 0;
	if (ft_map_bits(line,info) == 1 && ft_check_pars(info))
	{
		if (ft_strlen(line) > info->iline_size)
			info->iline_size = ft_strlen(line);
		info->iline_num++;
		//todo: fix /n/n bug
//		if (info->map_start == 1)
//		{
//
//		}
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
	else if (ft_map_bits(str,info) == 1)
	{
		if (ft_check_pars(info) == 0)
			ft_error("Map must be after parameters\n",info);
		else
		{
			info->map_start = 1;
			ft_map_params(str, info);
		}
	}
}

int ft_map_char(char c)
{
	if (c != ' ' && c != '0' && c != '1' &&
		c != '2' && c != 'N' && c != 'S'
		&& c != 'E' && c != 'W' && c != '\n'
		&& c != '\t')
		return (0);
	return (1);
}


/*validate map*/
int ft_map_bits(char *line, t_info *info)
{
	int i;
	if(!line)
		return (0);
	if (ft_map_char(line[0]))
	{
		i = -1;
		if (line == "\n")
			ft_error("Wrong map\n",info);
		while (line[++i])
		{
			/*check valid map bits in line*/
			if (ft_map_char(line[i]) == 0)
				return (0);
		}
	}
	else
		return (0);
	return (1);

}

void ft_parse_map(char *str, t_info *info)
{
	int fd;
	int rd;
	char *line;

	rd = 1;
	line = NULL;
	if (info->iline_size == 0 || info->iline_num == 0)
		ft_error("Map not passed\n",info);
	//gnl + allocate memory
	//put spaces
	//check map valid
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
		if (ft_valid_str(line))
			ft_parse_params(line, info);
		else
			ft_error("File isn't valid\n" , info);
		/*count map size*/
		free(tmp);
	}
	ft_check_params(info);
	ft_parse_map(line, info);
	close(fd);
}

