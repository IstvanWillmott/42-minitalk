/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillmot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:11:54 by iwillmot          #+#    #+#             */
/*   Updated: 2022/03/30 18:07:53 by iwillmot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_countstr(char *string)
{
	int	i;

	i = 0;
	while (string[i])
		i++;
	return (i - 1);
}

int	ft_putnum(int str)
{
	int		i;
	char	*new;
	int		newleng;

	i = 0;
	new = ft_itoa(str);
	newleng = ft_countstr(new);
	i = ft_putstr(new);
	free(new);
	return (i);
}
