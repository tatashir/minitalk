/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:13:12 by tatashir          #+#    #+#             */
/*   Updated: 2022/12/08 18:55:28 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_big_sixteen(unsigned long int x)
{
	unsigned int	r;
	int				count;

	count = 0;
	r = x % 16;
	x = x / 16;
	if (0 < x)
		count += ft_putnbr_big_sixteen(x);
	if (0 <= r && r <= 9)
		count += ft_putchar((char)r + '0');
	else if (9 < r)
		count += ft_putchar('A' +(char)r - 10);
	return (count);
}

int	ft_putnbr_small_sixteen(unsigned long int x)
{
	unsigned int	r;
	int				count;

	count = 0;
	r = x % 16;
	x = x / 16;
	if (0 < x)
		count += ft_putnbr_small_sixteen(x);
	if (0 <= r && r <= 9)
		count += ft_putchar((char)r + '0');
	else if (9 < r)
		count += ft_putchar('a' +(char)r - 10);
	return (count);
}
