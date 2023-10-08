/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evella <evella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 02:47:01 by evella            #+#    #+#             */
/*   Updated: 2023/10/08 03:10:26 by evella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <libft.h>

int		ft_putnbr_hexa(long int n, int upper, int format);
int		ft_putchar(const char c);
int		ft_putstr(const char *s);
void	ft_putnbru(unsigned int n);
int		ft_printf(const char *s, ...);
int		ft_intlen(int n);

#endif
