/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:37:11 by hanisha           #+#    #+#             */
/*   Updated: 2020/11/24 14:41:11 by hanisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

#define BUFFER_SIZE 5

int		get_next_line(int fd, char **line);
size_t	ft_gstrlen(const char *str);
char	*ft_gstrjoin(char const *s1, char const *s2);
char	*ft_gstrdup(const char *str);
char	*ft_gstrchr(const char *str, int c);
char	*ft_gstrcpy(char *dest, char *src);

#endif
