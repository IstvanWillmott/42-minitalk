/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillmot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:29:50 by iwillmot          #+#    #+#             */
/*   Updated: 2022/08/01 16:29:51 by iwillmot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "ft_printf.h"

typedef struct s_serverreceive
{
	char	c;
	size_t	rec;
}	t_serverreceive;

t_serverreceive	g_message;

void	bit_receive(int bit)
{
	g_message.c += ((bit & 1) << g_message.rec);
	g_message.rec++;
	if (g_message.rec == 7)
	{
		ft_printf("%c", g_message.c);
		if (!g_message.c)
			ft_printf("\n");
		g_message.c = 0;
		g_message.rec = 0;
	}
}

int	main(void)
{
	ft_printf("Server PID: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR2, bit_receive);
		signal(SIGUSR1, bit_receive);
		pause();
	}
	return (0);
}
