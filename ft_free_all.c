#include "./includes/cub.h"

void ft_free_inftext(t_info *info)
{
	if (info->no)
		free(info->no);
	if (info->so)
		free(info->so);
	if (info->we)
		free(info->we);
	if (info->ea)
		free(info->ea);
	if (info->s)
		free(info->s);
}


void ft_free_all(t_info *info)
{
	if (info->map)
		free(info->map);
//	if (info->str_map)
//		free(info->str_map);
//	if (info->pre_map)
//		free(info->pre_map);
	ft_free_inftext(info);
}