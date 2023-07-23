/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:30:02 by ahmadzaaza        #+#    #+#             */
/*   Updated: 2023/07/23 23:43:58 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

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
      ft_parse(str[i++], args);
      count++;
    } else {
      ft_putchar(str[i++]);
    }
  }
  va_end(args);
  return count;
}

// #include "stdio.h"

// int main(void) {
//   ft_printf("Ours is %c\n", 42);
//   printf("Original is %c\n", 42);
//   return 0;
// }