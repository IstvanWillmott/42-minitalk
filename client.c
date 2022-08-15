/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillmot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:29:45 by iwillmot          #+#    #+#             */
/*   Updated: 2022/08/01 16:29:46 by iwillmot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "ft_printf.h"

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

void	kill_bits(int pid, char *str, size_t len)
{
	int		shift;
	size_t	i;

	i = 0;
	while (i <= len)
	{
		shift = 0;
		while (shift < 7)
		{
			if ((str[i] >> shift) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			shift++;
			usleep(50);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;

	if (argc != 3)
	{
		ft_printf("Expected: ./client <PID> <MESSAGE>\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	str = argv[2];
	kill_bits(pid, str, ft_strlen(str));
	return (0);
}
