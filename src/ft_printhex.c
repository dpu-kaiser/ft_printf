/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:50:35 by dkaiser           #+#    #+#             */
/*   Updated: 2024/03/13 16:00:38 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int get_len(unsigned int n)
{
    int len;

    len = 0;
    if (n == 0)
        return 1;
    while (n)
    {
        len++;
        n /= 16;
    }
    return len;
}

static void printhex_rec(unsigned int nbr, char fmt)
{
    char c;

    if (nbr % 16 < 10)
        c = '0' + (nbr % 16);
    else
        c = fmt - 35 + (nbr % 16);
    if (nbr > 15)
        printhex_rec(nbr, fmt);
    write(1, &c, 1);
}

int ft_printhex(unsigned int nbr, char fmt)
{
    printhex_rec(nbr, fmt);
    return get_len(nbr);
}
