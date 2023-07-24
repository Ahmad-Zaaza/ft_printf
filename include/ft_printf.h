/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:28:39 by ahmadzaaza        #+#    #+#             */
/*   Updated: 2023/07/24 10:03:19 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

#define FT_PRINTF_H

#include "libft.h"
#include <stdarg.h>

int ft_printf(const char *, ...);

void ft_parse(char c, va_list *args, int *count);

int ft_putchar(char c);
int ft_putstr(char *s);
int ft_putnbr(int n);
void ft_puthex(unsigned long n, int *count);
int ft_putmem(unsigned long n);

#endif