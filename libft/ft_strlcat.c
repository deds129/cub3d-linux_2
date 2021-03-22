/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:34:37 by hanisha           #+#    #+#             */
/*   Updated: 2020/11/02 13:10:42 by hanisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t nb)
{
	size_t	i;
	size_t	dsize;

	dsize = 0;
	while (dest[dsize] != '\0' && dsize < nb)
		dsize++;
	i = dsize;
	while (src[dsize - i] != '\0' && dsize + 1 < nb)
	{
		dest[dsize] = src[dsize - i];
		dsize++;
	}
	if (i < nb)
		dest[dsize] = '\0';
	return (ft_strlen(src) + i);
}
