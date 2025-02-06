/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:25:19 by lpradene          #+#    #+#             */
/*   Updated: 2022/11/29 14:29:06 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *s, ...);
int	ft_putformated(va_list params, char c);

int	ft_putstr(char *s);
int	ft_putchar(char c);

int	ft_puthex(unsigned long long n);

int	ft_putnbr(int n);

int	ft_putunbr(unsigned int n);

int	ft_strlen(const char *s);
int	ft_putchar(char c);
int	ft_putstr(char *s);

int	ft_putptr(unsigned long long n);

#endif
