/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:28:39 by ahmadzaaza        #+#    #+#             */
/*   Updated: 2023/07/23 23:27:59 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

#define FT_PRINTF_H

#include "libft.h"
#include <stdarg.h>

int ft_printf(const char *, ...);

void ft_parse(char c, va_list args);

void ft_putchar(char c);
void ft_putstr(char *s);
void ft_putnbr(int n);
void ft_puthex(unsigned long n);

#endif