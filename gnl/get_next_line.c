/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 16:26:02 by hanisha           #+#    #+#             */
/*   Updated: 2021/01/06 17:36:47 by hanisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

void				ft_gbzero(char *s)
{
	size_t				i;

	i = 0;
	if (s != NULL)
		while (s[i])
		{
			((char *)s)[i] = 0;
			i++;
		}
}

void				n_line(char **p_n, char **rem, char **buff, char ***line)
{
	char		*tmp;

	if ((*p_n = (ft_gstrchr(*buff, '\n'))))
	{
		*(*p_n) = '\0';
		tmp = *rem;
		*rem = ft_gstrdup(++(*p_n));
		free(tmp);
	}
	**line = ft_gstrjoin(**line, *buff);
}

char				*remainer_check(char *remainer, char **line)
{
	char	*p_nextline;

	p_nextline = NULL;
	if (remainer)
		if ((p_nextline = ft_gstrchr(remainer, '\n')))
		{
			*p_nextline = '\0';
			*line = ft_gstrdup(remainer);
			p_nextline++;
			ft_gstrcpy(remainer, p_nextline);
		}
		else
		{
			*line = ft_gstrdup(remainer);
			ft_gbzero(remainer);
		}
	else
		*line = ft_gstrdup("");
	return (p_nextline);
}

int					fr(char **str)
{
	if (*str != NULL)
		free(*str);
	*str = NULL;
	return (0);
}

int					get_next_line(int fd, char **line)
{
	char		*buff;
	int			read_byte;
	static char	*rem;
	char		*p_nextline;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (!(buff = (char *)(malloc(sizeof(char) * (BUFFER_SIZE + 1)))))
	{
		fr(&buff);
		return (-1);
	}
	p_nextline = remainer_check(rem, line);
	while (!p_nextline && (read_byte = read(fd, buff, BUFFER_SIZE)))
	{
		if (read_byte == -1)
		{
			fr(&buff);
			return (-1);
		}
		buff[read_byte] = '\0';
		n_line(&p_nextline, &rem, &buff, &line);
	}
	free(buff);
	return ((read_byte || p_nextline || ft_gstrlen(rem)) ? 1 : fr(&rem));
}
