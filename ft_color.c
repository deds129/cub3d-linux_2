#include "./includes/cub.h"

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
		printf("C: %d %d %d\n",rgb[0],rgb[1],rgb[2]);
		info->cell = ft_color_to_hex(rgb[0],rgb[1],rgb[2]);
		info->has_param[7]++;
	}
	else if (str[0] == 'F')
	{
		printf("F: %d %d %d\n",rgb[0],rgb[1],rgb[2]);
		info->floor = ft_color_to_hex(rgb[0],rgb[1],rgb[2]);
		info->has_param[6]++;
	}
}