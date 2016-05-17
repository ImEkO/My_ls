#include "my_ls.h"

int  my_strcmp(char *s1, char *s2)
{
  int  w;

  w = 0;
  while (s1[w] != '\0' || s2[w] != '\0')
    {
      if (s1[w] < s2[w])
        {
          return (-1);
        }
      if (s1[w] == s2[w])
        {
          w = w + 1;
        }
      if (s1[w] > s2[w])
        {
          return (1);
	}
    }
  return (0);
}

int  my_strlen(char *str)
{
  int  d;

  d = 0;

  while (*str != '\0')
    {
      d = d + 1;
      str = str + 1;
    }
  return (d);
}

char**	my_sort_tab(char **tab, int size)
{
  int	draa;
  int	droo;
  char*	swap;

  draa = 0;
  droo = 0;
  while (draa < size)
    {
      droo = 0;
      while (droo < size)
	     {
	        if (tab[draa][0] < tab[droo][0])
	         {
	            swap = tab[draa];
	            tab[draa] = tab[droo];
	            tab[droo] = swap;
	          }
	          droo = droo + 1;
	      }
      draa = draa + 1;
    }
  return (tab);
}

char**	my_sort_tab_2(char **tab, int size)
{
  int	draa;
  int	droo;
  char*	swap;

  draa = 0;
  droo = 0;
  while (draa < size)
    {
      droo = 0;
      while (droo < size)
	     {
	        if (tab[draa][0] > tab[droo][0])
	         {
	            swap = tab[draa];
	            tab[draa] = tab[droo];
	            tab[droo] = swap;
	          }
	          droo = droo + 1;
	      }
      draa = draa + 1;
    }
  return (tab);
}

void aff_tab(char** tab)
{
  int i;
  int y;

  y = 0;
  while (tab[y] != '\0')
    {
      y++;
    }
  i = 0;
  tab = my_sort_tab(tab, y);
  while (tab[i] != '\0')
    {
      my_putstr(tab[i]);
      my_putstr("  ");
      i++;
    }
}
