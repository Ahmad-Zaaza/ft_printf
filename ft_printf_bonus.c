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

#include "include/ft_printf_bonus.h"
#include <stdio.h>

void ft_parse(char c, va_list *args, int *char_count) {
  if (c == 'c')
    *char_count += ft_putchar(va_arg(*args, int));
  else if (c == 's')
    *char_count += ft_putstr(va_arg(*args, char *));
  else if (c == 'p')
    *char_count += ft_putmem(va_arg(*args, unsigned long int));
  else if (c == 'd')
    ft_putnbr(va_arg(*args, int), char_count);
  else if (c == 'i')
    ft_putnbr(va_arg(*args, int), char_count);
  else if (c == 'x' || c == 'X')
    ft_puthex(va_arg(*args, unsigned int), char_count, c);
  else if (c == 'u')
    ft_putunbr(va_arg(*args, unsigned int), char_count);
  else if (c == '%')
    *char_count += ft_putchar('%');
}

void handle_conversion(const char *str, va_list *args, int *i, int *count) {
  int char_count;
  char_count = 0;
  
  ft_parse(str[*i], args, &char_count);
  *i += 1;
}

void handle_width(const char *str, va_list *args, int *i, int *count) {
  int digit;
  int spaces;
  int j;

  j = *i;
  spaces = 0;
  if (str[j] == '-') {
    spaces++;
    j++;
  }
  while (str[j] >= '0' && str[j] <= '9') {
    spaces++;
    j++;
  }

  digit = ft_atoi(str + *i);
  *i += spaces;
  printf("Spaces: %d\n", spaces);
  printf("i is: %c\n", str[*i]);
  // printf("%-10d", 50234);
  if (digit < 0) {
    ft_parse(str[*i], args, count);
    while (digit < 0) {
      ft_putchar(' ');
      digit++;
    }
  } else {
    while (digit > 0) {
      ft_putchar(' ');
      digit--;
    }
    ft_parse(str[*i], args, count);
  }
}
// void handle_width(const char *str, va_list *args, int *i, int *count) {
//   int digit;

//   digit = ft_atoi(str + *i);
//   // printf("Digit is : %d\n", digit);
//   if (digit == 0) {
//     ft_parse(str[*i], args, count);
//   } else if (digit < 0) {
//     ft_parse(str[*i], args, count);
//     while (digit < 0) {
//       ft_putchar(' ');
//       digit++;
//     }
//     *i -= digit;
//   } else {
//     while (digit > 0) {
//       ft_putchar(' ');
//       digit--;
//     }
//     ft_parse(str[*i], args, count);
//     *i += digit;
//   }
// }

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
      handle_conversion(str, &args, &i, &count);
      i++;
    } else {
      count += ft_putchar(str[i]);
      i++;
    }
  }
  va_end(args);
  return count;
}

int main(void) {

  ft_printf("%10s\n", "50234");
  printf("%10s\n", "50234sasdqw");
  // printf("%10d", 50234);

  // printf(" %c %c %c \n", 'c', 0, 'a');
  // ft_printf("Ours is %c\n %s\n %c\n", 42, "65", 97);
  // printf("Original is %c\n %s\n %c\n", 42, "65", 97);
  return 0;
}