#include "./includes/cub.h"

void ft_map_params(char *line, t_info *info)
{
	int i;
	i = 0;
	if (ft_map_bits(line, info) == 1 && info->map_start == 0)
	{
		//добавить условия
		if ((int)ft_strlen(line) > info->iline_size)
			info->iline_size = ft_strlen(line);
		info->iline_num++;
		//todo: fix /n/n bug

	}
}

/*validate map*/
int ft_map_bits(char *line, t_info *info)
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
//todo: fix wrong char map
			if (ft_map_char(line[i]) == 0)
				return (0);
		}
	}
	else
		return (0);
	return (1);

}

void ft_copy_map(t_info	*info)
{
	int i;
	int j;

	i = -1;
	if (!(info->pre_map))
		ft_error("Map not passed\n", info);
	if (!(info->map = malloc(sizeof(char *) * info->iline_num)))
		ft_error("Malloc error\n",info);

	while (info->pre_map[++i])
	{
		j = -1;
		if (!(info->map[i] = malloc(sizeof(char) * info->iline_size + 1)))
			ft_error("Malloc error\n",info);
		while (info->pre_map[i][++j])
		{
			info->map[i][j] = info->pre_map[i][j];
		}
//		j++;
//		while (j < info->iline_size)
//		{
//			info->map[i][j] = ' ';
//			j++;
//		}
		info->map[i][j] = '\0';
	}
	free(info->pre_map);
}

//todo: parse map
void ft_parse_map(t_info *info)
{
	int fd;
	int rd;
	char *line;
	char *tmp;

	tmp = NULL;
	fd = open(info->filename, O_RDONLY);
	if (info->iline_size == 0 || info->iline_num == 0)
		ft_error("Map not passed\n",info);
	printf("lines num: %d\n", info->iline_num);
	printf("line size: %d\n", info->iline_size);
	rd = 1;
	line = NULL;
	while (rd > 0)
	{
		rd = get_next_line(fd, &line);
		if (ft_map_bits(line, info) == 1)
		{
			if (!(info->str_map))
				info->str_map = ft_strdup(line);
			else
			{
				tmp = ft_strjoin(info->str_map,"\n");
				free(info->str_map);
				info->str_map = ft_strjoin(tmp,line);
				free(tmp);
			}
		}
		free(line);
	}
	info->pre_map = ft_split(info->str_map, '\n');
	ft_copy_map(info);
	//todo: do this cases
	//put spaces
	//check map valid
	//errors handle
}