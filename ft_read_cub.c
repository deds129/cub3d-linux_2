#include "./includes/cub.h"

void ft_check_params(t_info *info)
{
	int i;
	i = -1;
	while (++i < 8)
	{
		//todo: free duplicate
		if(info->has_param[i] == 0)
			ft_error("Missing arguments\n" , info);
		if(info->has_param[i] > 1)
			ft_error("Too many arguments\n" , info);
	}
}

void ft_parse_params(char *str, t_info *info)
{
	if(str[0] == 'R')
		ft_set_res(++str, info);
	else if(str[0] == 'C' || str[0] == 'F')
		ft_set_colors(str, info);
	else if((str[0] == 'N' && str[1] == 'O') ||
			(str[0] == 'W' && str[1] == 'E') ||
			(str[0] == 'E' && str[1] == 'A') ||
			(str[0] == 'S')
			)
		ft_set_textures(str, info);
}
/*validate map*/
int ft_map_bits(char *line, t_info *info)
{
	int i;
	if(!line)
		return (0);
	if (line[0] == ' ' || line[0] == '1')
	{
		i = -1;
		while (line[++i])
		{
			/*check valid map bits in line*/
			if (line[i] != ' ' && line[i] != '0' && line[i] != '1' &&
				line[i] != '2' && line[i] != 'N' && line[i] != 'S'
				&& line[i] != 'E' && line[i] != 'W' && line[i] != '\n'
				&& line[i] != '\t')
				return (0);
		}
		printf("%s\n", line);
	}
	return (1);

}
void ft_map_params(char *line, t_info *info)
{
	int i;
	i = 0;
	if (ft_map_bits(line,info) == 1)
	{
		printf("%s\n", line);
	}
}




void ft_read_cub(int fd, t_info *info)
{
	int rd;
	char *line;
	char *tmp;

	rd = 1;
	while (rd > 0)
	{
		rd = get_next_line(fd, &line);
		tmp = line;
		line += ft_skip_spaces(line);
		if (ft_valid_str(line))
		{
			ft_parse_params(line, info);
			//ft_map_params(line,info);
			ft_map_bits(line, info);
		}
		else
			ft_error("File isn't valid\n" , info);
		/*count map size*/
		free(tmp);
	}
	ft_check_params(info);
	close(fd);
}

