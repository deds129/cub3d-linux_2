#include "./includes/cub.h"

void ft_map_params(char *line, t_info *info)
{
	int i;
	i = 0;
	if (ft_map_bits(line,info) == 1 && info->map_start == 0)
	{
		//printf("%s\n", line);
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
			if (ft_map_char(line[i]) == 0)
				return (0);
		}
	}
	else
		return (0);
	return (1);

}

void ft_parse_map(char *filename,t_info *info)
{
	int fd;
	int rd;
	char *line;
	int str_num;
	str_num = -1;


	fd = open(info->filename, O_RDONLY);
	if (info->iline_size == 0 || info->iline_num == 0)
		ft_error("Map not passed\n",info);

	if(!(info->map = malloc(sizeof(char) * (info->iline_num *
											(info->iline_size + 1)))))
		ft_error("Malloc error\n", info);
	rd = 1;
	line = NULL;
	while (rd > 0)
	{
		rd = get_next_line(fd, &line);
		//todo: upgrade
		if (ft_map_bits(line,info) == 1)
		{

		}
		free(line);
	}


	//gnl + allocate memory
	//put spaces
	//check map valid
}