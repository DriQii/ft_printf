/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 03:18:39 by evella            #+#    #+#             */
/*   Updated: 2023/10/08 03:20:15 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_args_two(char const c, va_list args)
{
	int	i;
	int	j;

	i = -2;
	j = 0;
	if (c == 'c')
	{
		i++;
		ft_putchar(va_arg(args, int));
	}
	else if (c == 's')
		i += ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
	{
		j = va_arg(args, int);
		ft_putnbr(j);
		i += ft_intlen(j);
	}
	else if (c == 'u')
	{
		j = va_arg(args, unsigned int);
		ft_putnbru(j);
		i += ft_intlen(j);
	}
	return (i);
}

static int	ft_print_args(char const c, va_list args)
{
	int	i;

	i = -2;
	if (c == 'c' || c == 's' || c == 'd' || c == 'i' || c == 'u')
		return (ft_print_args_two(c, args));
	else if (c == '%')
		i += ft_putchar('%');
	else if (c == 'p')
		i += ft_putnbr_hexa((long int)va_arg(args, void *), 0, 0);
	else if (c == 'x')
		i += ft_putnbr_hexa(va_arg(args, long int), 0, 1);
	else if (c == 'X')
		i += ft_putnbr_hexa(va_arg(args, long int), 1, 1);
	return (i);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] != '%')
			write(1, &s[i], 1);
		else
		{
			count += ft_print_args(s[i + 1], args);
			i++;
		}
		i++;
	}
	return (i + count);
}
