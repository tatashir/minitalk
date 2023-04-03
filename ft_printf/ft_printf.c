/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:15:18 by tatashir          #+#    #+#             */
/*   Updated: 2022/12/05 08:58:22 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vfprintf(const char *format, va_list ap)
{
	int	count;

	count = 0;
	if (*format == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (*format == 'd' || *format == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (*format == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (*format == 'x')
		count += ft_putnbr_small_sixteen(va_arg(ap, unsigned int));
	else if (*format == 'X')
		count += ft_putnbr_big_sixteen(va_arg(ap, unsigned int));
	else if (*format == 'p')
		count += ft_putadrs(va_arg(ap, uintptr_t));
	else if (*format == 'u')
		count += ft_put_u_nbr(va_arg(ap, unsigned int));
	else if (*format == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	ap;

	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
			count += ft_putchar(*format);
		else
		{
			format++;
			count += ft_vfprintf(format, ap);
		}
		format++;
	}
	va_end(ap);
	if (INT_MAX < count)
		return (-1);
	return (count);
}
