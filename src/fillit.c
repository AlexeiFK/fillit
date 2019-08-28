/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 17:51:40 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/03/25 22:57:05 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "fillit.h"

static int	is_out_of_bounds(int i, int j, int size)
{
	if ((j + 1) > size)
		return (0);
	if ((i + 1) > size)
		return (0);
	if (j < 0)
		return (0);
	if (i < 0)
		return (0);
	return (1);
}

static void	inc(int *i, int *j)
{
	(*i)++;
	(*j)++;
}

int			check_space(char **map, int i, int j, t_fi *f)
{
	int			t_i;
	int			t_j;
	int			temp_j;

	t_i = 0;
	adjustment(f->id, &j, f);
	temp_j = j;
	while (t_i < 4)
	{
		t_j = 0;
		while (t_j < 4)
		{
			if (f->tetr_arr[f->id]->arr[t_i][t_j] != '.')
			{
				if (!(is_out_of_bounds(i, j, f->size)))
					return (0);
				if (map[i][j] != '.')
					return (0);
			}
			inc(&j, &t_j);
		}
		j = temp_j;
		inc(&i, &t_i);
	}
	return (1);
}

void		write_in_map(char **map, int i, int j, t_fi *f)
{
	int			t_i;
	int			t_j;

	adjustment(f->id, &j, f);
	t_i = 0;
	while (t_i < 4)
	{
		t_j = 0;
		while (t_j < 4)
		{
			if (f->tetr_arr[f->id]->arr[t_i][t_j] != '.')
				(map[i][j] = f->tetr_arr[f->id]->arr[t_i][t_j]);
			j++;
			t_j++;
		}
		j -= 4;
		i++;
		t_i++;
	}
}

char		**create_map(int size)
{
	char	**map;
	int		i;
	int		j;

	map = (char**)malloc(sizeof(char*) * size);
	i = 0;
	while (i < size)
	{
		map[i] = (char*)malloc(sizeof(char) * size);
		j = 0;
		while (j < size)
		{
			map[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}
