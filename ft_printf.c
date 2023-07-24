/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:30:02 by ahmadzaaza        #+#    #+#             */
/*   Updated: 2023/07/24 09:48:02 by ahmadzaaza       ###   ########.fr       */
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
      ft_parse(str[i], &args);
      i++;
    } else {
      ft_putchar(str[i]);
      i++;
    }
    count++;
  }
  va_end(args);
  return count;
}

// #include "stdio.h"

// int main(void) {

//   // char *str = "hello world";
//   ft_printf(" %c %c %c \n", 'c', 'c', 'a');
//   ft_printf(" %c %c %c \n", 'c', 'c', 'a');
//   // printf(" %c %c %c \n", 'c', 0, 'a');
//   // ft_printf("Ours is %c\n %s\n %c\n", 42, "65", 97);
//   // printf("Original is %c\n %s\n %c\n", 42, "65", 97);
//   return 0;
// }