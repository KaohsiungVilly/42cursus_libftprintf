/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillena <pvillena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:33:18 by pvillena          #+#    #+#             */
/*   Updated: 2022/02/08 22:44:39 by pvillena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_putstr_print(char *s, int *print)
{
	if (!s)
		return (NULL);
	while (*s != '%' && *s)
		ft_putchar(*s++, print);
	return (s);
}

void	ft_print_percentage(const char *s, int *print, va_list p)
{
	while (*s)
	{
		s = ft_putstr_print((char *)s, print);
		if (!*s)
			return ;
		else if (*(s + 1) == 'c')
			ft_putchar(va_arg(p, int), print);
		else if (*(s + 1) == 's')
			ft_putstr(va_arg(p, char *), print);
		else if (*(s + 1) == 'p')
			ft_address(va_arg(p, unsigned long int), print);
		else if (*(s + 1) == 'd' || *(s + 1) == 'i')
			ft_putnbr(va_arg(p, int), print);
		else if (*(s + 1) == 'u')
			ft_unsigned_putnbr(va_arg(p, unsigned int), print);
		else if (*(s + 1) == 'x' || *(s + 1) == 'X')
			ft_hex(va_arg(p, unsigned int), print, *(s + 1));
		else if (*(s + 1) == '%')
			ft_putchar('%', print);
		s += 2;
	}
}

int	ft_printf(const char *s, ...)
{
	va_list	p;
	int		print;

	if (!s)
		return (0);
	print = 0;
	va_start(p, s);
	ft_print_percentage(s, &print, p);
	va_end(p);
	return (print);
}
