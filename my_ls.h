#ifndef __my_ls_h__
#define __my_ls_h__

#include <stdlib.h>
#include <getopt.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <ctype.h>

struct dirent* readdir(DIR* repertoire) ;
struct stat fileStat;
struct passwd *pwd;
struct group  *grp;
struct tm *p;
DIR* rep;
struct dirent* fichierLu;

void    my_putchar(char c);
void    my_putstr(char *str);
void    my_put_nbr(int n);
void    aff_tab(char** tab);
void    aff_tab_2(char** tab);
void    ls_perm();
void    ls_affich();
void    ls_infos_l();


char**	my_sort_tab(char **tab, int size);
char**	my_sort_tab_2(char **tab, int size);

int     gestion_erreur(int argc, char** argv, char c);
int     gestion_erreur_2(int argc, char** argv, char c);
int     my_strlen(char *str);
int     my_strcmp(char *s1, char *s2);
int     my_int(char* argv);
int     my_getnbr(char *str);
int     ls_a();
int     my_ls();
int     ls_A();
int     ignore_signs(char *str, int i, int sign);
int     main(int argc, char** argv);
int     ls_d();
int     ls_r();
int     ls_l();
int     ls_d_2(char** argv);
int     ls_r_2(char** argv);
int     ls_A_2(char** argv);
int     ls_a_2(char** argv);
int     ls_l_2(char** argv);
int     my_ls_arg(char** argv);

char    get_opt(int argc, char** argv);
#endif
