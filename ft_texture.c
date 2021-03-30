#include "./includes/cub.h"

void 	ft_valid_path_check(char **path, t_info *info)
{
	int fd;
	int len;
	char *suffix;
	char buf;

	fd = open(*path, O_RDONLY);
	if(read(fd, &buf, 1) < 0 || fd == -1)
		ft_error("Can't open texture path\n", info);
	close(fd);
	len = ft_strlen(*path);
	suffix = ft_strdup(*path);
	if (suffix[len - 3] != 'x' && suffix[len - 2] != 'p' && suffix[len - 1]
															!= 'm')
	{
		free(suffix);
		ft_error("Wrong texture extension\n", info);
	}
	free(suffix);
}

int	ft_check_space(char *str, t_info *info)
{
	if(str[0] != ' ')
	{
		ft_error("Bad texture parameter\n", info);
		return (0);
	}
	return (1);
}

void ft_set_path(char *str, t_info *info, char **path, int idx)
{
	info->has_param[idx]++;
	while (*str != ' ')
		str++;
	str += ft_skip_spaces(str);
	if (info->has_param[idx] < 2)
		*path = ft_strtrim(str," ");
	ft_valid_path_check(path,info);

}
void ft_set_textures(char *str, t_info *info)
{
	if(str[0] == 'N' && str[1] == 'O' && ft_check_space((str + 2),info))
		ft_set_path((str + 2),info, &info->no,1);
	else if(str[0] == 'W' && str[1] == 'E' && ft_check_space((str + 2),info))
			ft_set_path((str + 2),info, &info->we,3);
	else if(str[0] == 'E' && str[1] == 'A' && ft_check_space((str + 2),info))
		ft_set_path((str + 2),info, &info->ea,4);
	else if(str[0] == 'S' && str[1] == 'O' && ft_check_space((str + 2),info))
		ft_set_path((str + 2),info, &info->so,2);
	else if(str[0] == 'S' && ft_check_space((str + 1),info))
		ft_set_path((str + 1),info, &info->s,5);
}
