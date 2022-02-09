/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillena <pvillena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:50:36 by pvillena          #+#    #+#             */
/*   Updated: 2022/02/08 22:41:19 by pvillena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
void	ft_putchar(char c, int *print);
void	ft_putstr(char *s, int *print);
void	ft_aux_putnbr(int n, int *print);
void	ft_putnbr(int n, int *print);
void	ft_unsigned_putnbr(unsigned int n, int *print);
void	ft_hex(unsigned int n, int *print, char c);
void	ft_print_hex(unsigned int n, int *print, char c);
void	ft_address(unsigned long int n, int *print);
#endif