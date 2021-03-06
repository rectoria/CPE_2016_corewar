/*
** my_strndup.c for libmy in /home/rectoria/delivery/Projets/CPE_2016_corewar/src/vm
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Fri Mar 31 18:09:33 2017 Bastien
** Last update Fri Mar 31 18:11:31 2017 Bastien
*/

#include <stdlib.h>

char	*my_strndup(char *str, int len)
{
  char	*new;
  int	i;

  i = -1;
  if ((new = malloc(sizeof(char) * (len + 1))) == 0)
    return (0);
  while (++i < len)
    new[i] = str[i];
  new[i] = 0;
  return (new);
}
