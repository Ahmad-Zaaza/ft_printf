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

#ifndef FT_PRINTF_BONUS_H

#define FT_PRINTF_BONUS_H

#include "stdio.h"
#include <stdarg.h>
#include <unistd.h>

int ft_printf(const char *, ...);

void ft_parse(char c, va_list *args, int *char_count);
void handle_conversion(const char *str, va_list *args,int *i, int *count);

int ft_putchar(char c);
int ft_putstr(char *s);
void ft_putnbr(int n, int *count);
void ft_putunbr(unsigned int n, int *count);
void ft_puthex(unsigned long n, int *count, char c);
int ft_putmem(unsigned long n);
void handle_width(const char *str, va_list *args, int *i, int *count);
int ft_atoi(const char *str);

#endif