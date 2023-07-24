/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:30:02 by ahmadzaaza        #+#    #+#             */
/*   Updated: 2023/07/24 09:54:47 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

void ft_parse(char c, va_list *args, int *count) {
  if (c == 'c')
    *count += ft_putchar(va_arg(*args, int));
  else if (c == 's')
    *count += ft_putstr(va_arg(*args, char *));
  else if (c == 'p')
    *count += ft_putmem(va_arg(*args, unsigned long int));
  else if (c == 'd')
    ft_putnbr(va_arg(*args, int), count);
  else if (c == 'i')
    ft_putnbr(va_arg(*args, int), count);
  else if (c == 'x' || c == 'X')
    ft_puthex(va_arg(*args, unsigned int), count, c);
  else if (c == 'u')
    ft_putunbr(va_arg(*args, unsigned int), count);
  else if (c == '%')
    *count += ft_putchar('%');
}

int ft_printf(const char *str, ...) {
  va_list args;
  int i;
  int count;

  count = 0;
  i = 0;
  va_start(args, str);

  while (str[i]) {
    if (str[i] == '%') {
      i++;
      ft_parse(str[i], &args, &count);
      i++;
    } else {
      count += ft_putchar(str[i]);
      i++;
    }
  }
  va_end(args);
  return count;
}

// #include "stdio.h"

// int main(void) {

//   char *str = NULL;
//   ft_printf("%s\n", str);
//   printf("%s\n", str);

//   // printf(" %c %c %c \n", 'c', 0, 'a');
//   // ft_printf("Ours is %c\n %s\n %c\n", 42, "65", 97);
//   // printf("Original is %c\n %s\n %c\n", 42, "65", 97);
//   return 0;
// }