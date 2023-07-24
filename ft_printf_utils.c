/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 23:16:06 by ahmadzaaza        #+#    #+#             */
/*   Updated: 2023/07/24 10:29:34 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include <stdarg.h>

void ft_parse(char c, va_list *args, int *count) {
  if (c == 'c')
    *count += ft_putchar(va_arg(*args, int));
  else if (c == 's')
    *count += ft_putstr(va_arg(*args, char *));
  else if (c == 'p')
    *count += ft_putmem(va_arg(*args, unsigned long int));
  else if (c == 'd')
    *count += ft_putnbr(va_arg(*args, int));
  else if (c == 'i')
    *count += ft_putnbr(va_arg(*args, int));
  else if (c == 'x')
    *count += ft_puthex(va_arg(*args, unsigned int));
  else if (c == 'X')
    *count += ft_puthex(va_arg(*args, unsigned int));
  else if (c == 'u')
    *count += ft_putnbr(va_arg(*args, unsigned int));
  else if (c == '%')
    *count += ft_putchar('%');
}

int ft_putchar(char c) {
  write(1, &c, 1);
  return 1;
}

int ft_putstr(char *str) {
  int i;

  i = 0;
  while (str[i])
    ft_putchar(str[i++]);

  return i;
}

int ft_putnbr(int n) {
  long int nb;
  char cnbr;
  int count;

  count = 0;
  nb = n;
  if (nb < 0) {
    nb = -nb;
    write(1, "-", 1);
    count++;
  }
  while (n > 9) {
    count += ft_putchar(n % 10);
    n = n / 10;
  }
  cnbr = nb + 48;
  write(1, &cnbr, 1);
  count++;
  return count;
}

int ft_puthex(unsigned long n) {
  char *hex;
  int count;

  count = 0;
  hex = "0123456789abcdef";
  while (n > 15) {
    count += ft_putchar(hex[n % 16]);
    n = n / 16;
  }
  count += ft_putchar(hex[n % 16]);
  return count;
}

int ft_putmem(unsigned long n) {
  ft_putchar(48);
  ft_putchar('x');
  return ft_puthex(n) + 2;
}