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

int		g_size = 0;

static int	is_out_of_bounds(int i, int j)
{
	if ((j + 1) > g_size)
		return (0);
	if ((i + 1) > g_size)
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

int			check_space(char **map, int i, int j, int id)
{
	int			t_i;
	int			t_j;
	int			temp_j;

	t_i = 0;
	adjustment(id, &j);
	temp_j = j;
	while (t_i < 4)
	{
		t_j = 0;
		while (t_j < 4)
		{
			if (g_tetr_arr[id]->arr[t_i][t_j] != '.')
			{
				if (!(is_out_of_bounds(i, j)))
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

void		write_in_map(char **map, int i, int j, int id)
{
	int			t_i;
	int			t_j;

	adjustment(id, &j);
	t_i = 0;
	while (t_i < 4)
	{
		t_j = 0;
		while (t_j < 4)
		{
			if (g_tetr_arr[id]->arr[t_i][t_j] != '.')
				(map[i][j] = g_tetr_arr[id]->arr[t_i][t_j]);
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

	g_size = size;
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
