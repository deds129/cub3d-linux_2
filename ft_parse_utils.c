#include "./includes/cub.h"

void ft_print_params(t_info *info)
{
	printf("=====================\n");
	printf("res_x: %d\n",info->res_x);
	printf("res_y: %d\n",info->res_y);
	printf("no_texture: %s\n",info->no);
	printf("so_texture: %s\n",info->so);
	printf("we_texture: %s\n",info->we);
	printf("ea_texture: %s\n",info->ea);
	printf("s_texture: %s\n",info->s);
	printf("floor_color_r: %i\n",info->floor_r);
	printf("floor_color_g: %i\n",info->floor_g);
	printf("floor_color_b: %i\n",info->floor_b);
	printf("celling_color_r: %i\n",info->cell_r);
	printf("celling_color_g: %i\n",info->cell_g);
	printf("celling_color_b: %i\n",info->cell_b);
	printf("\n===MAP===\n");
//	int i;
//	i = -1;
//	while(info->map[++i])
//		printf("%s\n",info->map[i]);

}


int ft_valid_str(char *data)
{
	if (data[0] == 'R' || data[0] == 'N' || data[0] == 'S' ||
		data[0] == 'W' || data[0] == 'E' || data[0] == 'F' ||
		data[0] == 'C' || data[0] == '\n' || data[0] == ' ' ||
		data[0] == '1' || data[0] == '\0')
		return (1);
	return (0);
}

int ft_count_lines(char **temp)
{
	int i;

	//todo: check null-case
	i = 0;
	while (temp[i])
		i++;
	return (i);
}

int ft_check_digit(char *line)
{
	int i;

	//todo: check null-case
	i = -1;
	while (line[++i])
	{
		if(!(ft_isdigit(line[i])))
			return (0);
	}
	return (1);
}
//return new string with replaced char to new char
//malloc problem
char *ft_chrrep(char *str,char chr, char new_chr)
{
	int i;
	i = 0;
	char *tmp;
	tmp = ft_strdup(str);
	while(tmp[i])
	{
		if(tmp[i] == chr)
			tmp[i] = new_chr;
		i++;
	}
	return (tmp);
}

