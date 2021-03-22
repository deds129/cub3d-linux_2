#include "./includes/cub.h"

void ft_error(int err_code)
{
	if(err_code == ERR_MALLOC)
		ft_putstr_fd("Error\nmalloc() error!\n",2);
	else if (err_code == ERR_ARGC_MIN)
		ft_putstr_fd("Error\nMap not passed",2);
	else if (err_code == ERR_ARGC_MAX)
		ft_putstr_fd("Error\nToo many arguments",2);
	else if (err_code == ERR_ARG_SAVE)
		ft_putstr_fd("Error\nIncorrect save argument.",2);

	else if (err_code == ERR_FILENAME)
		ft_putstr_fd("Error\nIncorrect map extension.\n",2);
	else if (err_code == ERR_FILE_OPEN)
		ft_putstr_fd("Error\nCan't read file.\n",2);
	else if (err_code == ERR_FILE_ISDIR)
		ft_putstr_fd("Error\nFile is directory.\n",2);

	else if (err_code == ERR_MAP_READ)
		ft_putstr_fd("Error\nCan't read map",2);
	else if (err_code == ERR_MAP_VALIDITY)
		ft_putstr_fd("Error\nMap isn't valid",2);
	else if (err_code == ERR_MAP_RES)
		ft_putstr_fd("Error\nMap params are bad. Check R parameter.\n",2);
	else if (err_code == ERR_MAP_T)
		ft_putstr_fd("Error\nMap params are bad. Check texture parameters.\n",2);
	else if (err_code == ERR_MAP_C)
		ft_putstr_fd("Error\nMap params are bad. Check colors.\n",2);
	else if (err_code == ERR_MAP_OPEN)
		ft_putstr_fd("Error\nMap borders are open.\n",2);
	exit(EXIT_FAILURE);
}

