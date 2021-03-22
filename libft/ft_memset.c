/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 17:01:19 by hanisha           #+#    #+#             */
/*   Updated: 2020/11/02 15:02:31 by hanisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	size_t				i;
	unsigned char		*s1;

	s1 = (unsigned char *)s;
	i = 0;
	while (i < len)
	{
		s1[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
