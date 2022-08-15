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

/*Once a signal is receieved, each bit is converted back into a char. A global
variable is used in this situation to keep track of each character. Notice
the conversion is the opposite of how the char was deconstructed in client.
Once the full bit string is recieved (when rec == 7 aka, we have recieved 8 bits)
the character is printed, the global variables reset and the process 
restarted until no more characters are received, upon which a newline
is printed.*/

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

/*The server prints its PID, this is an identifier used by the client
to transfer bits. It then enters a while loop where it continuously
looks for signals. Once a signal is recieved it passes it to bit_receive.*/

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
