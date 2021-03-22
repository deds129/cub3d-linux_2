/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 14:42:58 by hanisha           #+#    #+#             */
/*   Updated: 2020/11/16 14:43:06 by hanisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	indexator(char const *s1, char const *set)
{
	size_t				i;
	size_t				j;
	size_t				flag;

	i = 0;
	while (s1[i])
	{
		j = 0;
		flag = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				break ;
			else
			{
				flag++;
				j++;
			}
		}
		if (flag >= ft_strlen(set))
			return (i);
		i++;
	}
	return (-1);
}

static int	revindexator(char const *s1, char const *set)
{
	size_t i;
	size_t j;
	size_t flag;

	i = ft_strlen(s1) - 1;
	while (s1[i])
	{
		j = 0;
		flag = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				break ;
			else
			{
				flag++;
				j++;
			}
		}
		if (flag >= ft_strlen(set))
			return (i);
		i--;
	}
	return (-1);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char				*trimstr;
	size_t				start;
	size_t				len;
	size_t				temp;

	if (!s1 || !set)
		return (NULL);
	start = indexator(s1, set);
	temp = revindexator(s1, set);
	len = temp - start + 1;
	if (start >= temp)
		return (ft_strdup(""));
	trimstr = ft_substr(s1, start, len);
	return (trimstr);
}
