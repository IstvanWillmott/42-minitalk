/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillmot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 14:30:21 by iwillmot          #+#    #+#             */
/*   Updated: 2022/08/05 14:30:25 by iwillmot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char	*str)
{
	int	ret;
	int	neg;
	int	i;

	ret = 0;
	neg = 1;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if ((str[i] == '+') && ((str[i + 1] >= '0') && (str[i + 1] <= '9')))
		i++;
	else if ((str[i] == '-') && ((str[i + 1] >= '0') && (str[i + 1] <= '9')))
	{
		neg = -1;
		i++;
	}
	else if ((str[i] <= '0') && (str[i] >= '9'))
		return (0);
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		ret = ret * 10 + (str[i] - 48);
		i++;
	}
	return (ret * neg);
}

size_t	ft_strlen(char const *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}
