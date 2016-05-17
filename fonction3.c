#include "my_ls.h"

void aff_tab_2(char** tab)
{
  int i;
  int y;

  y = 0;
  while (tab[y] != '\0')
    {
      y++;
    }
  i = 0;
  tab = my_sort_tab_2(tab, y);
  while (tab[i] != '\0')
    {
      my_putstr(tab[i]);
      my_putstr("  ");
      i++;
    }
}

int  my_int(char* argv)
{
  int  i;

  i = 0;
  while (argv[i] != '\0')
    {
      if (argv[i] < 48 || argv[i] > 57)
        return (0);
      i++;
    }
  return (1);

}
