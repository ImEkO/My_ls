#include "my_ls.h"

char c;

char get_opt(int argc, char** argv)
{
  char optstring[]="aAdlr";

  while ((c=getopt(argc, argv, optstring)) != EOF)
  {
    if (argc == 2 && argv[1][0] == '-')
      gestion_erreur(argc, argv, c);
    else if (argc == 3)
      gestion_erreur_2(argc, argv, c);
    }
  return (c);
}

int  gestion_erreur(int argc, char** argv, char c)
{
  char* strg;
  int (*tab[5]) ();
  int i;

  i = 0;
  if (argc){}
  if (argv){}
  strg = "darlA";
  tab[0] = &ls_d;
  tab[1] = &ls_a;
  tab[2] = &ls_r;
  tab[3] = &ls_l;
  tab[4] = &ls_A;
  while ( strg[i] != '\0' )
    {
      if (c == strg[i])
        (*tab[i])();
          i++;
      }
  my_putstr("\n");
  return (0);
}

int  gestion_erreur_2(int argc, char** argv, char c)
{
  char* strg;
  int (*tab[5]) ();
  int i;

  i = 0;
  strg = "Adrla";
  tab[0] = &ls_A_2;
  tab[1] = &ls_d_2;
  tab[2] = &ls_r_2;
  tab[3] = &ls_l_2;
  tab[4] = &ls_a_2;
  if (argc){}
  while ( strg[i] != '\0' )
    {
     if (c == strg[i])
       (*tab[i])(argv);
     i++;
   }
  my_putstr("\n");
  return (0);
}

int main(int argc, char** argv)
{
  if (argc == 1)
    my_ls();
  else if (argc == 2 && argv[1][0] != '-')
      my_ls_arg(argv);
  else
    get_opt(argc, argv);
  return (0);
}
