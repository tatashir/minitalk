/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:33:39 by tatashir          #+#    #+#             */
/*   Updated: 2023/04/03 15:09:34 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char ft_conversion_bit_10(int a_2)
{
    int rtn;
    int num;
    while(0 < a_2)
    {
        rtn = rtn + ((a_2 % 10) * num);
        a_2 = a_2 /10;
        num *= 2;
    }
    return ((char)rtn);
}

