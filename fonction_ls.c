#include "my_ls.h"

int   my_ls()
{
  int i;
  char** tab;

  rep = NULL;
  i = 0;
  tab = malloc(sizeof(char*) * 100);
  fichierLu = NULL;
  rep = opendir("./");
  while ((fichierLu = readdir(rep)) != NULL)
  {
    if (fichierLu->d_name[0] != '.' && fichierLu->d_name != '\0')
      {
        tab[i] = fichierLu->d_name;
        i++;
      }
  }
  if (closedir(rep) == -1)
    return(0);
  aff_tab(tab);
  my_putstr("\n");
  free(tab);
  return (0);
}

int   ls_a()
{
  int i;
  char** tab;

  rep = NULL;
  i = 0;
  fichierLu = NULL;
  tab = malloc(sizeof(char*) * 100);
  rep = opendir("./");
  if (rep == NULL)
    {
      my_putstr("No such file or directory !\n");
      return (0);
    }
  while ((fichierLu = readdir(rep)) != NULL)
  {
    tab[i] = fichierLu->d_name;
    i++;
  }
  if (closedir(rep) == -1)
    return(0);
  aff_tab(tab);
  free(tab);
  return (0);
}

int   ls_A()
{
  int i;
  char** tab;

  rep = NULL;
  i = 0;
  fichierLu = NULL;
  tab = malloc(sizeof(char*) * 100);
  rep = opendir("./");
  if (rep == NULL)
    {
      my_putstr("No such file or directory !\n");
      return (0);
    }
  while ((fichierLu = readdir(rep)) != NULL)
  {
    if (my_strcmp(fichierLu->d_name, "..") != 0 && my_strcmp(fichierLu->d_name, ".") != 0)
    {
      tab[i] = fichierLu->d_name;
      i++;
    }
  }
  if (closedir(rep) == -1)
    return(0);
  aff_tab(tab);
  free(tab);
  return (0);
}

int   ls_d()
{
  int i;
  char** tab;

  rep = NULL;
  i = 0;
  fichierLu = NULL;
  rep = opendir("./");
  tab = malloc(sizeof(char*) * 100);
  if (rep == NULL)
  {
    my_putstr("No such file or directory !\n");
    return (0);
  }
  while ((fichierLu = readdir(rep)) != NULL)
  {
    if (fichierLu->d_name[0] == '.' && fichierLu->d_name[1] == '\0' && my_strcmp(fichierLu->d_name, "..") != 0)
      {
        tab[i] = fichierLu->d_name;
        i++;
      }
    }
    if (closedir(rep) == -1)
      return(0);
    aff_tab(tab);
    free(tab);
    return (0);
}

int   ls_r()
{
  int i;
  char** tab;

  rep = NULL;
  i = 0;
  tab = malloc(sizeof(char*) * 100);
  fichierLu = NULL;
  rep = opendir("./");
  if (rep == NULL)
  {
    my_putstr("No such file or directory !\n");
    return (0);
  }
  while ((fichierLu = readdir(rep)) != NULL)
  {
    if (fichierLu->d_name[0] != '.' && fichierLu->d_name != '\0')
      {
        tab[i] = fichierLu->d_name;
        i++;
      }
  }
  if (closedir(rep) == -1)
    return(0);
  aff_tab_2(tab);
  free(tab);
  return (0);
}
