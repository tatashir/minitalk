/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 18:13:49 by tatashir          #+#    #+#             */
/*   Updated: 2023/04/05 16:40:14 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int id_check(char *argv)
{
    int i;

    i = 0;
    while (argv[i] != '\0')
    {
        if (!ft_isdigit(argv[i]))
            return (1);
        i++;
    }
    return (0);
}

int arguments_check(int argc, char **argv)
{
    int n;

    if (argc != 3)
        return (1);
    if (id_check(argv[1]))
        return (1);
    n = ft_atoi(argv[1]);
    if (n < 0 || 99999 < n)
        return (1);
    return (0);
}

static void conversion_2bit(int n, char str[9])
{
    int i;
    int j;
    int rbase;

    i = 0;
    j = 7;
    while (0 <= j)
    {
        rbase = 1 << i;
        rbase = n & rbase;
        str[j] = (rbase >> i) + '0';
        i++;
        j--;
    }
}

int main(int a_argc, char *a_argv[])
{
    int i;
    int j;
    char r_str[9];

    if (arguments_check(a_argc, a_argv))
        return (0);
    i = 0;
    r_str[8] = '\0';
    while (a_argv[2][i] != '\0')
    {
        conversion_2bit((int)a_argv[2][i], r_str);
        j = 0;
        while (j < 8)
        {
            if (r_str[j] == '1')
                kill((pid_t)ft_atoi(a_argv[1]), SIGUSR1);
            else if (r_str[j] == '0')
                kill ((pid_t)ft_atoi(a_argv[1]), SIGUSR2);
            j++;
            usleep(450);
        }
        i++;
    }
    return (0);
}
