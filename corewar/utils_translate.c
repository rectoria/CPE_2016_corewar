/*
** utils_translate.c for vm in /home/rectoria/delivery/Projets/CPE_2016_corewar
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Sun Apr  2 12:00:39 2017 Bastien
** Last update Sun Apr  2 12:00:42 2017 Bastien
*/

#include "vm.h"

void		my_memncpy(void *dest, void *src, int n)
{
  char		*dests;
  char		*srcs;
  int		i;

  dests = dest;
  srcs = src;
  i = -1;
  while (++i < n)
    dests[i] = srcs[i];
}

int		binary_to_type(char code)
{
  const char	type[3] = {T_REG, T_DIR, T_IND};
  int		i;

  i = -1;
  while (++i < 3)
    {
      if (code == i + 1)
	return (type[i]);
    }
  return (0);
}

int		inst_to_time(char inst)
{
  const int	time[17] = {0, 10, 5, 5, 10, 10, 6, 6, 6, 20,
			    25, 25, 800, 10, 50, 1000, 2};

  if (inst > 16 || inst < 0)
    return (0);
  return (time[(int) inst]);
}

int		type_to_size(char inst, char type)
{
  const char    types[3] = {T_REG, T_DIR, T_IND};
  const char    size[3] = {1, 4, 2};
  int           i;

  if ((inst == 10 || inst == 11 || inst == 14) &&
      type == T_DIR)
    return (2);
  i = -1;
  while (++i < 3)
    if (types[i] == type)
      return (size[i]);
  return (0);
}
