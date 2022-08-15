/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillmot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 10:55:48 by iwillmot          #+#    #+#             */
/*   Updated: 2022/03/30 18:11:59 by iwillmot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*mall(long int nn, int len, int neg)
{
	char	*ret;

	if (neg < 1)
	{
		len++;
		ret = malloc(len + 1);
	}
	else
		ret = malloc(len + 1);
	ret[len] = '\0';
	len--;
	while (len >= 0)
	{
		ret[len] = (nn % 10) + 48;
		nn = (nn / 10);
		len--;
	}
	if (neg < 1)
		ret[0] = '-';
	return (ret);
}

int	length(long int nn)
{
	int	i;

	i = 1;
	while (nn > 9)
	{
		nn = (nn / 10);
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			i;
	int			neg;
	int			len;
	long int	nn;

	i = 0;
	neg = 1;
	len = 1;
	nn = n;
	if (nn < 0)
	{
		nn = -nn;
		neg = -1;
	}
	len = length(nn);
	return (mall(nn, len, neg));
}
