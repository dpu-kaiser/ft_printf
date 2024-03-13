/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:18:40 by dkaiser           #+#    #+#             */
/*   Updated: 2024/03/13 15:49:00 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <unistd.h>

static int get_len(long n)
{
    int len;

    len = 0;
    if (n == 0)
        return 1;
    if (n < 0)
        len++;
    while (n)
    {
        len++;
        n /= 10;
    }
    return len;
}

int ft_printnbr(int nbr)
{
    ft_putnbr_fd(nbr, 1);
    return get_len(nbr);
}

static void	printunbr_rec(unsigned int n)
{
	char	c;

	c = '0' + n % 10;
	if (n > 9)
		printunbr_rec(n / 10);
	write(1, &c, 1);
}

int ft_printunbr(unsigned int nbr)
{
    printunbr_rec(nbr);
    return get_len(nbr);
}
