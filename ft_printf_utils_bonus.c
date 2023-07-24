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

#include "include/ft_printf_bonus.h"

int ft_putchar(char c) {
  write(1, &c, 1);
  return 1;
}

int ft_putstr(char *str) {
  int i;

  if (!str) {
    ft_putstr("(null)");
    return 6;
  }
  i = 0;
  while (str[i])
    ft_putchar(str[i++]);

  return i;
}

void ft_puthex(unsigned long n, int *count, char c) {
  char *hex;
  if (c == 'x')
    hex = "0123456789abcdef";
  else
    hex = "0123456789ABCDEF";
  if (n > 15) {
    ft_puthex(n / 16, count, c);
  }
  *count += ft_putchar(hex[n % 16]);
}

int ft_putmem(unsigned long n) {
  int count;

  if (!n) {
    ft_putstr("(nil)");
    return 5;
  }
  ft_putchar(48);
  ft_putchar('x');
  count = 2;
  ft_puthex(n, &count, 'x');
  return count;
}

void ft_putnbr(int n, int *count) {
  long int nb;

  nb = n;
  if (nb < 0) {
    nb = -nb;
    *count += ft_putchar('-');
  }
  if (nb > 9) {
    ft_putnbr(nb / 10, count);
  }
  *count += ft_putchar(nb % 10 + 48);
}

void ft_putunbr(unsigned int n, int *count) {
  long int nb;

  nb = n;
  if (nb < 0) {
    nb = -nb;
    *count += ft_putchar('-');
  }
  if (nb > 9) {
    ft_putnbr(nb / 10, count);
  }
  *count += ft_putchar(nb % 10 + 48);
}
