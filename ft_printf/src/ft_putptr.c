/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillmot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:01:52 by iwillmot          #+#    #+#             */
/*   Updated: 2022/03/09 14:12:35 by iwillmot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_write_hex_ptr(unsigned long long c, char *i)
{
	if (c >= 16)
	{
		ft_write_hex_ptr(c / 16, i);
		ft_write_hex_ptr(c % 16, i);
	}
	else
	{
		if (c <= 9)
		{	
			c = c + '0';
			write(1, &c, 1);
			i[0]++;
		}
		else
		{
			c = c - 10 + 'a';
			write(1, &c, 1);
			i[0]++;
		}
	}
}

int	ft_putptr(unsigned long long ptr)
{
	char	*i;
	int		g;

	i = malloc(1);
	i[0] = 0;
	i[0] += write(1, "0x", 2);
	if (ptr == 0)
		i[0] += write(1, "0", 1);
	else
		ft_write_hex_ptr(ptr, i);
	g = i[0];
	free (i);
	return (g);
}
