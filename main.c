#include "./includes/cub.h"

static int ft_check_str(char *str, char *s, int num)
{
	size_t len;
	len = 0;
	if (*str && (len = ft_strlen(str)))
	{
		if (len < 5)
			return (0);
		if (!(ft_strncmp(&str[len - num], s, num)))
			return (1);
	}
	return (0);
}

void ft_parse_args(int ac, char *filename, char *save)
{
	int flag;
	flag = 0;
	if (!(ft_check_str(filename, ".cub", 4)))
		ft_error(ERR_FILENAME);
	if (ac == 2 && !save)
		flag = 1;
	else if (ac == 3 && save != NULL)
		flag = ft_check_str(save, "--save", 6);
	if (!flag)
		ft_error(ERR_ARG_SAVE);
}

int ft_open_cub(char *filename)
{
	int fd;
	if ((fd = open(filename, O_DIRECTORY)) != -1)
		ft_error(ERR_FILE_ISDIR);
	if ((fd = open(filename, O_RDONLY)) == -1)
		ft_error(ERR_FILE_OPEN);
	return (fd);
}


int main (int argc, char *argv[])
{
	t_info info;
	int fd;
	ft_bzero(&info,sizeof(info));
	fd = ft_open_cub(argv[1]);
	if (argc == 2 || argc == 3)
	{
		if (argc == 2)
			ft_parse_args(2, argv[1], NULL);
		else if (argc == 3)
		{
			ft_parse_args(3, argv[1], argv[2]);
			info.save = 1;
		}
		ft_read_cub(fd, &info);
	//	ft_print_params(&info);
	}
	else
		ft_error(ERR_ARGC_MIN);
	close(fd);
	//todo: make free func
	free(info.data);
	free(info.no);
	free(info.so);
	free(info.we);
	free(info.ea);
	free(info.s);
	return (0);
}

