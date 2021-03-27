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

char *ft_wo_spaces_str(char *wo_str, char *str)
{
	int i;
	int j;
	int len;

	i = 0;
	j = 0;
	len = ft_strlen(str + 1) - ft_spaces_num(str + 1);
	if (!(wo_str = (char *)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	wo_str[len] = 0;
	while (str[i])
	{
		if (str[i] != ' ')
		{
			wo_str[j] = str[i];
			j++;
		}
		i++;
	}
	return (wo_str);
}

int ft_valid_color_str(char *str, t_info *info)
{
	int commas;
	int nums;
	int i;
	char *wo_spaces;

	i = 0;
	commas = ft_commas_num(str);
	nums = ft_num_counter(str);
	if (str[1] != ' ' || commas != 2 || nums != 3)
		ft_error(ERR_MAP_C);
	if(!(wo_spaces = ft_wo_spaces_str(NULL, str + 1)))
		ft_error(ERR_MAP_C);
	while (wo_spaces[++i])
	{
		if(wo_spaces[i] == ',')
		{
			if (!(ft_isdigit(wo_spaces[i - 1]))
				|| !(ft_isdigit(wo_spaces[i + 1])))
				ft_error(ERR_MAP_C);
		}
	}
	free(wo_spaces);
}

void	ft_color_val(char **str, int *color)
{
	ft_skip_not_num(str);
	if (ft_isdigit(**str) || **str == '-')
		*color = ft_atoi(*str);
	ft_skip_num(str);
}

//error
void	ft_check_color(int color)
{
	if (color > 255 || color < 0)
		ft_error(ERR_MAP_C);
}
void ft_fill_color(t_info *info, int rgb[3], char *str)
{
	int i;

	i = -1;
	while (++i < 3)
	{
		ft_color_val(&str, &rgb[i]);
		ft_check_color(rgb[i]);
	}
}



void	ft_set_colors(char *str, t_info *info)
{
	int rgb[3];
	ft_valid_color_str(str, info);
	ft_fill_color(info, rgb, str);
	if(str[0] == 'C')
	{
		//prarams++
		info->cell = ft_color_to_hex(rgb[0],rgb[1],rgb[2]);
	}
	else if (str[0] == 'F')
	{
		//params++
		info->floor = ft_color_to_hex(rgb[0],rgb[1],rgb[2]);
	}
}

void 	ft_valid_path_check(char **path, t_info *info)
{
	int fd;
	int len;
	char *suffix;
	char buf;

	fd = open(*path, O_RDONLY);
	if(read(fd, &buf, 1) < 0 || fd == -1)
		ft_error(ERR_MAP_C);
	close(fd);
	len = ft_strlen(*path);
	suffix = ft_strdup(*path);
	if (suffix[len - 3] != 'x' && suffix[len - 2] != 'p' && suffix[len - 1]
	!= 'm')
	{
		free(suffix);
		ft_error(ERR_MAP_C);
	}
	free(suffix);
}

int	ft_check_space(char *str, t_info *info)
{
	if(str[0] != ' ')
	{
		ft_error(ERR_MAP_C);
		return (0);
	}
	return (1);
}

void ft_set_path(char *str, t_info *info, char **path)
{

	//printf("%s\n",str);
	*path = ft_strtrim(str," ");
	printf("%s\n", *path);
	//todo: free allocated path dir in struct .. now in main
	ft_valid_path_check(path,info);

}
void ft_get_path(char *str, t_info *info)
{
	if(str[0] == 'N' && str[1] == 'O' && ft_check_space((str + 2),info))
	{
		ft_set_path((str + 2),info, &info->no);
	}
	else if(str[0] == 'W' && str[1] == 'E' && ft_check_space((str + 2),info))
	{
		ft_set_path((str + 2),info, &info->we);
	}
	else if(str[0] == 'E' && str[1] == 'A' && ft_check_space((str + 2),info))
	{
		ft_set_path((str + 2),info, &info->ea);
	}
	else if(str[0] == 'S' && str[1] == 'O' && ft_check_space((str + 2),info))
	{
		ft_set_path((str + 2),info, &info->so);
	}
	else if(str[0] == 'S' && ft_check_space((str + 1),info))
	{
		ft_set_path((str + 1),info, &info->s);
	}
}


void ft_set_textures(char *str, t_info *info)
{
	//get_path_from_file
	ft_get_path(str, info);
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
		if (info->dup_flag == 1)
			ft_error(ERR_MAP_D);
		/*set params*/
		//todo: hasparams+ to check + muliply check
		if (ft_valid_str(line))
			ft_parse_params(line, info);
		else
			ft_error(ERR_MAP_BAD);
		/*count map size*/
		free(line);
	}
	close(fd);
}

