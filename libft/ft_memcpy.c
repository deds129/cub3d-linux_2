/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 17:08:22 by hanisha           #+#    #+#             */
/*   Updated: 2020/10/30 17:38:31 by hanisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dst, const void *rsrc, size_t n)
{
	size_t				i;
	unsigned char		*udst;
	unsigned char		*ursrc;

	udst = (unsigned char *)dst;
	ursrc = (unsigned char *)rsrc;
	if (!dst && !rsrc)
		return (dst);
	i = 0;
	while (i < n)
	{
		udst[i] = ursrc[i];
		i++;
	}
	return (udst);
}
