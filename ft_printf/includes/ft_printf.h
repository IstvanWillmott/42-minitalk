/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillmot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:07:23 by iwillmot          #+#    #+#             */
/*   Updated: 2022/03/09 13:38:22 by iwillmot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_putstr(char *str);
int		ft_putnum(int str);
int		ft_hexadecimal(unsigned int num, char format);
int		ft_putnum_unsigned(unsigned int num);
int		ft_putptr(unsigned long long ptr);

char	*ft_itoa(int n);

#endif
