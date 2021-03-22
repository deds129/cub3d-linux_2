#include "./includes/cub.h"

void            pixel_put(t_win *wnd, int x, int y, int color)
{
	char    *dst;

	dst = wnd->addr + (y * wnd->line_l + x * (wnd->bpp / 8));
	*(unsigned int*)dst = color;
}

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

//todo: malloc problem
void ft_make_map(t_list **head, int amount, t_info *info)
{
	t_list *tmp;
	int i;

	if (!(info->data = malloc((amount + 1) * sizeof(char *))))
		ft_error(ERR_MALLOC);
	i = -1;
	tmp = *head;
	while (tmp)
	{
		info->data[++i] = ft_strdup(tmp->content);
		tmp = tmp->next;
	}
	ft_lstclear(head,free);
}

void ft_read_cub(char *filename, t_info *info)
{
	char *line;
	t_list *head;
	int amount;
	int fd;
	int rb;
	line = NULL;
	head = NULL;
	amount = 0;
	if ((fd = open(filename, O_DIRECTORY)) != -1)
		ft_error(ERR_FILE_ISDIR);
	if ((fd = open(filename, O_RDONLY)) == -1)
		ft_error(ERR_FILE_OPEN);
	rb = get_next_line(fd, &line);
	if (rb <= 0)
		ft_error(ERR_FILE_OPEN);
	while (rb > 0)
	{
		ft_lstadd_back(&head, ft_lstnew(line));
		rb = get_next_line(fd, &line);
	}
	close(fd);
	ft_lstadd_back(&head, ft_lstnew(line));
	amount = ft_lstsize(head);
	ft_make_map(&head, amount, info);
	ft_lstclear(&head,free);
}



int main (int argc, char *argv[])
{
	t_info info;

	ft_bzero(&info,sizeof(info));
	if (argc == 2 || argc == 3)
	{
		if (argc == 2)
			ft_parse_args(2, argv[1], NULL);
		else if (argc == 3)
		{
			ft_parse_args(3, argv[1], argv[2]);
			info.save = 1;
		}
		ft_read_cub(argv[1], &info);

		ft_parse(&info);
	}
	else
		ft_error(ERR_ARGC_MIN);
	free(info.data);
	return (0);
}

