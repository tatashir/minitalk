/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:37:18 by tatashir          #+#    #+#             */
/*   Updated: 2022/12/18 11:22:33 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include "libft.h"

int	ft_putstr(char	*s);
int	ft_putchar(char c);
int	ft_putnbr(int n);
int	ft_put_u_nbr(unsigned int n);
int	ft_putnbr_big_sixteen(unsigned int long x);
int	ft_putnbr_small_sixteen(unsigned int long x);
int	ft_putadrs(uintptr_t ptr);
int	ft_vfprintf(const char *format, va_list ap);
int	ft_printf(const char *format, ...);

#endif
