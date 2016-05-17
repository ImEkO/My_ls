#include "my_ls.h"

void ls_perm()
{
  my_putstr( (S_ISDIR(fileStat.st_mode))  ? "d" : "-");
  my_putstr( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
  my_putstr( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
  my_putstr( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
  my_putstr( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
  my_putstr( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
  my_putstr( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
  my_putstr( (fileStat.st_mode & S_IROTH) ? "r" : "-");
  my_putstr( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
  my_putstr( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
  my_putstr(" ");
}

void ls_affich()
{
  int a;
  char* tmp;

  tmp = ctime(&fileStat.st_mtime);
  for (a = 4; a < my_strlen(tmp) - 9; a++)
      my_putchar(tmp[a]);
  my_putstr("  ");
}


void ls_infos_l()
{
  pwd = getpwuid(fileStat.st_uid);
  grp = getgrgid(fileStat.st_gid);
  my_put_nbr(fileStat.st_nlink);
  my_putstr(" ");
  my_put_nbr(fileStat.st_size);
  my_putstr(" ");
  my_putstr(pwd->pw_name);
  my_putstr(" ");
  my_putstr(grp->gr_name);
  my_putstr(" ");
}
int   ls_l()
{
  if ((rep = opendir("./")) == NULL)
    return (EXIT_FAILURE);
  while ((fichierLu = readdir(rep)) != NULL)
  {
    if (fichierLu->d_name[0] != '.')
    {
      if(stat(fichierLu->d_name,&fileStat) < 0)
          return 1;
    ls_perm();
    ls_infos_l();
    ls_affich();
    my_putstr(fichierLu->d_name);
    my_putstr("\n");
    }
  }
  if (closedir(rep) == -1)
    return (0);
  return (0);
}

int   ls_l_2(char** argv)
{
  rep = opendir(argv[2]);
  if (rep == NULL)
    return 0;
  while ((fichierLu = readdir(rep)) != NULL)
  {
    if (fichierLu->d_name[0] != '.')
    {
      if(stat(fichierLu->d_name,&fileStat) < 0)
          return 1;
    ls_perm();
    ls_infos_l();
    ls_affich();
    my_putstr(fichierLu->d_name);
    my_putstr("\n");
    }
  }
  if (closedir(rep) == -1)
 	 return (0);
  return (0);
}
