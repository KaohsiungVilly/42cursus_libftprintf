/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillena <pvillena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 22:32:05 by pvillena          #+#    #+#             */
/*   Updated: 2022/02/08 22:37:07 by pvillena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *print)
{
	write(1, &c, 1);
	(*print)++;
}

void	ft_putstr(char *s, int *print)
{
	if (!s)
	{
		ft_putstr("(null)", print);
		return ;
	}
	while (*s)
		ft_putchar(*s++, print);
}

void	ft_aux_putnbr(int n, int *print)
{
	if (n < 10)
		ft_putchar(n + 48, print);
	else
	{
		ft_aux_putnbr(n / 10, print);
		ft_putchar(n % 10 + 48, print);
	}
}

void	ft_putnbr(int n, int *print)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", print);
		return ;
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		(*print)++;
		n *= -1;
	}
	ft_aux_putnbr(n, print);
}

void	ft_unsigned_putnbr(unsigned int n, int *print)
{
	if (n < 10)
		ft_putchar(n + 48, print);
	else
	{
		ft_aux_putnbr(n / 10, print);
		ft_putchar(n % 10 + 48, print);
	}
}
