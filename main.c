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

void ft_parse_args(int ac, char *filename, char *save, t_info *info)
{
	int flag;
	flag = 0;
	if (!(ft_check_str(filename, ".cub", 4)))
		ft_error("Wrong file extension\n" , info);
	if (ac == 2 && !save)
		flag = 1;
	else if (ac == 3 && save != NULL)
		flag = ft_check_str(save, "--save", 6);
	if (!flag)
		ft_error("Wrong save flag\n" , info);
}

int ft_open_cub(char *filename, t_info *info)
{
	int fd;
	if ((fd = open(filename, O_DIRECTORY)) != -1)
		ft_error("File is directory\n" , info);
	if ((fd = open(filename, O_RDONLY)) == -1)
		ft_error("Can't open file\n" , info);
	return (fd);
}


int main (int argc, char *argv[])
{
	t_info info;
	int fd;
	ft_bzero(&info,sizeof(info));
	if (argc == 2 || argc == 3)
	{
		fd = ft_open_cub(argv[1], &info);
		if (argc == 2)
			ft_parse_args(2, argv[1], NULL, &info);
		else if (argc == 3)
		{
			ft_parse_args(3, argv[1], argv[2], &info);
			info.save = 1;
		}
		ft_read_cub(fd, &info);
		ft_print_params(&info);
	}
	else
		ft_error("Bad arguments\n",&info);
	close(fd);
	//todo: make free func
	ft_free_all(&info);
	return (0);
}

