#include "./includes/cub.h"

void ft_map_params(char *line, t_info *info)
{
	int i;
	i = 0;
	if (ft_map_bits(line) == 1 && info->map_start == 0)
	{
		//printf("%s\n", line);
		if ((int)ft_strlen(line) > info->iline_size)
			info->iline_size = ft_strlen(line);
		info->iline_num++;
		//todo: fix /n/n bug

	}
}

/*validate map*/
int ft_map_bits(char *line)
{
	int i;
	if(!line)
		return (0);

	if (ft_map_char(line[0]))
	{
		i = -1;
		while (line[++i])
		{
			/*check valid map bits in line*/
//			if (line[0] != '\n')
//				return (0);
			if (ft_map_char(line[i]) == 0)
				return (0);
		}
	}
	else
		return (0);
	return (1);

}

//void ft_fill_map_str(char *line,t_info *info, int *idx)
//{
//	int i;
//	i = *idx;
//	if(!(info->map[i] = malloc(sizeof(char) * (info->iline_size))))
//		ft_error("Malloc error\n", info);
//}
//

//todo: parse map
void ft_parse_map(t_info *info)
{
	int fd;
	int rd;
	char *line;
	char *str_map;
	char *tmp;
	int i;

	str_map = NULL;

	fd = open(info->filename, O_RDONLY);
	if (info->iline_size == 0 || info->iline_num == 0)
		ft_error("Map not passed\n",info);
	printf("lines num: %d\n", info->iline_num);
	printf("line size: %d\n", info->iline_size);

	//выделяем память под строки
	if(!(info->map = malloc(sizeof(char *) * (info->iline_num))))
		ft_error("Malloc error\n", info);
	rd = 1;
	line = NULL;
	i = 0;
	while (rd > 0)
	{
		rd = get_next_line(fd, &line);
		//todo: upgrade
		if (ft_map_bits(line) == 1)
		{
			//printf("%s\n", line);
			if (!(str_map))
				str_map = ft_strdup(line);
			else
			{
				tmp = str_map;
				str_map = ft_strjoin(str_map,line);
				free(tmp);
			}

		}
		free(line);

	}
	printf("%s\n",str_map);

	//todo: do this cases
	//put spaces
	//check map valid
	//errors handle
}