/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/thibrex/delivery/CPool_Day08
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu@epitech.net>
** 
** Started on  Wed Oct 12 11:08:17 2016 Thibaut Cornolti
** Last update Tue Mar 21 10:16:42 2017 Thibaut Cornolti
*/

#include <stdlib.h>
#include "my.h"

static int	contains_char(char *str, char c)
{
  int		i;

  i = -1;
  while (str[++i])
    if (str[i] == c)
      return (1);
  return (0);
}

static int	get_word_count(char *str, char *split)
{
  int		count;
  int		i;

  i = 0;
  count = 0;
  while (str[i] != 0)
    {
      if (contains_char(split, str[i]))
	count += 1;
      i += 1;
    }
  return (count + 1);
}

static char	**init_tab(char *str, char **tab, char *split)
{
  int		i;
  int		count;
  int		word;

  i = 0;
  count = my_strlen(str);
  word = get_word_count(str, split) - 1;
  tab = malloc(sizeof(char *) * (word + 2));
  if (tab == NULL)
    return ((char **) (long) my_puterror("error"));
  while (word >= 0)
    {
      if ((tab[word] = malloc(sizeof(char) * count + 1)) == NULL)
	return ((char **) (long) my_puterror("error"));
      tab[word][0] = 0;
      word -= 1;
    }
  return (tab);
}

char		**my_strsplit(char *str, char *split)
{
  int		i;
  int		j;
  int		k;
  char		**wordtab;

  wordtab = init_tab(str, wordtab, split);
  i = -1;
  j = 0;
  k = 0;
  while (str[++i] != 0)
    if (contains_char(split, str[i]) && k != 0)
      {
	k = 0;
	j += 1;
      }
    else if (!contains_char(split, str[i]))
      {
	wordtab[j][k] = str[i];
	wordtab[j][k + 1] = 0;
	k += 1;
      }
  if (wordtab[j][0] == 0)
    wordtab[j] = NULL;
  wordtab[j + 1] = NULL;
  return (wordtab);
}
