#include "my_ls.h"

void  my_putchar(char c)
{
  write(1, &c, 1);
}

void  my_putstr(char *str)
{
  while (*str != '\0')
    {
      my_putchar(*str);
      str++;
    }
}

void  my_put_nbr(int n)
{
  int d;
  int no;

  no = n;
  d = 1;
  if (no == -2147483648)
    {
      my_putstr("-2147483648");
      return ;
    }
  else if (n < 0)
    {
      my_putchar('-');
      no = - n;
    }
  while ((no / d) >= 10)
    {
      d = d * 10;
    }
  while (d > 0)
    {
      my_putchar((no / d) % 10 + 48);
      d = d / 10;
    }
}

int  ignore_signs(char *str, int i, int sign)
{
  int  n;
  int  cp;

  n = 0;
  while (str[i] && str[i] >= '0' && str[i] <= '9')
    {
      cp = n;
      if (cp > (n * 10 + (str[i] - '0')))
        return (0);
      n = n * 10 + (str[i++] - '0');
    }
  if (sign % 2 == 1)
    n = n * -1;
  return (n);
}

int             my_getnbr(char *str)
{
  int  i;
  int  nbre;
  int  minus;

  i = 0;
  minus = 0;
  while (str[i])
    {
      if (str[i] == '-')
	{
	  minus++;
	}
      if (str[i] >= '0' && str[i] <= '9')
        {
          nbre = ignore_signs(str, i, minus);
          return (nbre);
        }
      i++;
    }
  return (0);
}
