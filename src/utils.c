/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 03:13:35 by evella            #+#    #+#             */
/*   Updated: 2023/10/08 03:14:41 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putchar(const char c)
{
	write(1, &c, 1);
	return (1);
}

static unsigned int	ft_uintlen(unsigned int n)
{
	int	len;

	len = 1;
	while (n / 10 != 0)
	{
		len = len * 10;
		n = n / 10;
	}
	return (len);
}

void	ft_putnbru(unsigned int n)
{
	unsigned int	len;
	char			res;

	len = ft_uintlen(n);
	while (len >= 1)
	{
		res = n / len + '0';
		write (1, &res, 1);
		n = n % len;
		len = len / 10;
	}
}
