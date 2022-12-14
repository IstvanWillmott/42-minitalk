/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillmot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 12:22:46 by iwillmot          #+#    #+#             */
/*   Updated: 2022/03/30 18:06:11 by iwillmot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_find(va_list args, const char format)
{
	int		total_leng;

	total_leng = 0;
	if (format == 'c')
		total_leng += ft_putchar(va_arg(args, int));
	else if ((format == 'i') || (format == 'd'))
		total_leng += ft_putnum(va_arg(args, int));
	else if (format == 's')
		total_leng += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		total_leng += ft_putptr(va_arg(args, unsigned long long));
	else if ((format == 'x') || (format == 'X'))
		total_leng += ft_hexadecimal(va_arg(args, int), format);
	else if (format == 'u')
		total_leng += ft_putnum_unsigned(va_arg(args, int));
	else if (format == '%')
		total_leng += ft_putchar('%');
	else
		total_leng += ft_putchar(format);
	return (total_leng);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		total_leng;
	va_list	args;

	i = 0;
	total_leng = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '\0')
				break ;
			while ((str[i] >= '0') && (str[i] <= '9'))
				i++;
			total_leng += ft_find(args, str[i]);
		}
		else
			total_leng += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (total_leng);
}
