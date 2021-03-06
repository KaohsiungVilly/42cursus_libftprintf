/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillena <pvillena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 22:30:57 by pvillena          #+#    #+#             */
/*   Updated: 2022/02/08 22:38:32 by pvillena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hex(unsigned int n, int *print, char c)
{
	if (n < 16)
		ft_print_hex(n, print, c);
	else
	{
		ft_hex(n / 16, print, c);
		ft_print_hex(n % 16, print, c);
	}
}

void	ft_print_hex(unsigned int n, int *print, char c)
{
	if (c == 'x' && n >= 10)
		ft_putchar(n + 87, print);
	else if (c == 'X' && n >= 10)
		ft_putchar(n + 55, print);
	else if (n < 10)
		ft_putchar(n + 48, print);
}

void	ft_address(unsigned long int n, int *print)
{
	if (n < 16)
	{
		ft_putstr("0x", print);
		ft_print_hex(n, print, 'x');
	}
	else
	{
		ft_address(n / 16, print);
		ft_print_hex(n % 16, print, 'x');
	}
}
