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
	printf("sp_texture: %s\n",info->s);
	printf("floor_color: %i\n",info->floor);
	printf("celling_color: %i\n",info->cell);

	printf("\nparams check\n");
	printf("res: %d\n",info->has_param[0]);
	printf("no_texture: %d\n",info->has_param[1]);
	printf("so_texture: %d\n",info->has_param[2]);
	printf("we_texture: %d\n",info->has_param[3]);
	printf("ea_texture: %d\n",info->has_param[4]);
	printf("sp_texture: %d\n",info->has_param[5]);
	printf("floor_color: %d\n",info->has_param[6]);
	printf("celling_color: %d\n",info->has_param[7]);
	printf("\n===MAP===\n");
	int i;
	i = -1;
	while(info->map[++i])
		printf("%s\n",info->map[i]);
}

void ft_test_fill(t_info *info)
{
	char *str;
	str = "11111111\n10000111\n10000021\n10000001\n10200001\n10000N01\n11111111\n";
	info->map = ft_split(str,'\n');
}