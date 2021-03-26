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
	printf("%s\n", wo_spaces);
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

unsigned long	ft_color_to_hex(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
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
		//prarams++
		info->floor = ft_color_to_hex(rgb[0],rgb[1],rgb[2]);
	}
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

