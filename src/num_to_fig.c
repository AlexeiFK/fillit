/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_to_fig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 18:11:06 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/03/25 22:17:51 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include <stdio.h>

static void	get_starting_vars(int *i, int *sh, int *mv, int start)
{
	*i = 0;
	*sh = 0;
	*mv = (start % 5) + 1;
}

static void	next_line(int mv, int *start, int *i, int *j)
{
	*start += mv;
	if (mv != 1)
		(*i)++;
	*j = 0;
}

static void	str_to_tetr(t_tetr *new, char *str, int start, char c)
{
	int			i;
	int			j;
	int			mv;
	int			sh;

	get_starting_vars(&i, &sh, &mv, start);
	while (i < 4 && (sh < 4))
	{
		j = 0;
		while (j < 4 && (sh < 4))
		{
			if (str[start] == '\n')
				next_line(mv, &start, &i, &j);
			if (str[start] == '#')
			{
				sh++;
				new->arr[i][j] = c;
			}
			start++;
			j++;
		}
		i++;
	}
}

void		tetr_add(t_tetr *new, char *str, int start)
{
	static char c = 'A';

	str_to_tetr(new, str, start, c);
	c++;
}

t_tetr		*create_tetr(int id, char *str, int start)
{
	t_tetr		*new;
	int			i;
	int			j;

	if (!(new = (t_tetr*)malloc(sizeof(t_tetr))))
		return (NULL);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			new->arr[i][j] = '.';
			j++;
		}
		i++;
	}
	i = 0;
	id = 0;
	tetr_add(new, str, start);
	i = 0;
	return (new);
}
