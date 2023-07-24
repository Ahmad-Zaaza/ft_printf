
#include "../include/ft_printf_bonus.h"

int ft_atoi(const char *str) {
  long int result;
  long int old_result;
  int i;
  int sign;

  result = 0;
  i = 0;
  sign = 1;
  while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
    i++;
  if (str[i] == 45)
    sign = -1;
  i += (str[i] == '-' || str[i] == '+');
  while (str[i] >= '0' && str[i] <= '9') {
    old_result = result;
    result = (result * 10) + (str[i++] - 48);
    if (old_result > result) {
      if (sign < 0)
        return (0);
      return (-1);
    }
  }
  return (result * sign);
}
