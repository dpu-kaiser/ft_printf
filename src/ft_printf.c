/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:18:59 by dkaiser           #+#    #+#             */
/*   Updated: 2024/03/13 16:02:04 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdarg.h>

static int print_char(char c)
{
    ft_putchar_fd(c, 1);
    return 1;
}

static int print_str(char *str)
{
    if (str)
    {
        ft_putstr_fd(str, 1);
        return ft_strlen(str);
    }
    else
    {
        ft_putstr_fd("(null)", 1);
        return 6;
    }
}

static int print_conv(va_list args, char c)
{
    if (c == 'c')
        return print_char(va_arg(args, int));
    if (c == 's')
        return print_str(va_arg(args, char*));
    if (c == 'p')
        ;
    if (c == 'd' || c == 'i')
        return ft_printnbr(va_arg(args, int));
    if (c == 'u')
        return ft_printunbr(va_arg(args, unsigned int));
    if (c == 'x' || c == 'X')
        return ft_printhex(va_arg(args, unsigned int), c);
    if (c == '%')
        return print_char('%');
    return -2147483648;
}

int ft_printf(char *fmt, ...)
{
    int result;
    va_list args;

   result = 0;
   va_start(args, fmt);
   while(*fmt)
   {
       if (*fmt == '%')
           result += print_conv(args, *(++fmt));
       else
           result++;
       fmt++;
       if (result < 0)
           return -1;
   }
   va_end(args);
   return (result);
}
