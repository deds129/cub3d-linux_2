/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 13:41:43 by hanisha           #+#    #+#             */
/*   Updated: 2020/11/16 13:44:17 by hanisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	num_len(int n)
{
	size_t				len;
	long long int		n1;

	n1 = n;
	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n1 *= -1;
		len++;
	}
	while (n1 > 0)
	{
		n1 = n1 / 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n1)
{
	char				*str;
	size_t				len;
	long long int		n;

	n = (long long int)n1;
	len = num_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (n == 0)
	{
		str[0] = '0';
	}
	if (n < 0)
	{
		*str = '-';
		n *= -1;
	}
	while (n > 0)
	{
		str[len--] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
