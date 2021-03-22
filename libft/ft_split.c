/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 13:38:03 by hanisha           #+#    #+#             */
/*   Updated: 2020/11/18 13:38:07 by hanisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	ft_wcounter(char const *s, char c)
{
	size_t i;
	size_t counter;
	size_t len;

	if (!s || s[0] == '\0')
		return (0);
	counter = 0;
	i = 0;
	len = ft_strlen(s);
	if (s[0] != c)
		counter++;
	while (i < len - 1)
	{
		if (s[i] == c && s[i + 1] != c)
			counter++;
		i++;
	}
	return (counter);
}

static size_t	ft_wlen(char const *s, char c, int i)
{
	size_t idx;

	if (!s)
		return (0);
	idx = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		idx++;
	}
	return (idx);
}

static char		*ft_arrfill(char const *s, size_t len, size_t idx)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[idx];
		idx++;
		i++;
	}
	str[len] = '\0';
	return (str);
}

static char		**ft_arr_free(char **split)
{
	while (*split)
		free(*split++);
	free(split);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char				**split;
	size_t				i;
	size_t				j;
	size_t				temp;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (!(split = (char **)malloc(sizeof(char *) *
			(ft_wcounter((char *)s, c) + 1))))
		return (NULL);
	while (j < ft_wcounter((char *)s, c) && s[i] != '\0')
	{
		if (s[i] != c)
		{
			temp = ft_wlen((char *)s, c, i);
			if (!(split[j++] = ft_arrfill((char *)s, temp, i)))
				ft_arr_free(split);
			i += temp;
		}
		i++;
	}
	split[j] = NULL;
	return (split);
}
