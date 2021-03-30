#include "./includes/cub.h"

void ft_error(char *err_msg, t_info *info)
{
	write(1, "Error\n", 6);
	ft_putstr_fd(err_msg, 1);
	//change
	ft_free_all(info);
	exit(EXIT_FAILURE);
}
