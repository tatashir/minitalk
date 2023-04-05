/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:33:39 by tatashir          #+#    #+#             */
/*   Updated: 2023/04/05 16:23:34 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char conversion_10bit(int a_2)
{
    int rtn;
    int num;
    rtn = 0;
    num = 1;
    while(0 < a_2)
    {
        rtn = rtn + ((a_2 % 10) * num);
        a_2 = a_2 /10;
        num *= 2;
    }
    return ((char)rtn);
}

void    binary_converter(int num)
{
    static int r_binary_n;
    static int count;
    char r_put;

    if (num == SIGUSR1)
        r_binary_n = (r_binary_n * 10) + 1;
    if (num == SIGUSR2)
        r_binary_n = (r_binary_n * 10) + 0;
    count++;
    if (count == 8)
    {
        r_put = conversion_10bit(r_binary_n);
        write(1, &r_put, 1);
        r_binary_n = 0;
        count = 0;
        r_put = '\0';
    }
}

int main(void)
{
    struct sigaction r_sa;

    ft_bzero(&r_sa, sizeof(struct sigaction));
    r_sa.sa_handler = binary_converter;
    sigemptyset(&r_sa.sa_mask, SIGUSR1);
    sigaddset(&r_sa.sa_mask, SIGUSR1);
    sigaddset(&r_sa.sa_mask, SIGUSR2);
    r_sa.sa_flags = 0;
    ft_printf("%d\n", getpid());
    sigaction(SIGUSR1, &r_sa, NULL);
    sigaction(SIGUSR2, &r_sa, NULL);
    while (1)
        pause();
    return (0);
}
