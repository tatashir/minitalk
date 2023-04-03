/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:09:52 by tatashir          #+#    #+#             */
/*   Updated: 2022/12/05 09:12:49 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putadrs(uintptr_t point)
{
	int	count;

	count = 0;
	count += write(1, "0x", 2);
	if (!point)
		count += write (1, "0", 1);
	else
		count += ft_putnbr_small_sixteen((unsigned long int)point);
	return (count);
}
