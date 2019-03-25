/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 22:23:35 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/03/25 22:48:26 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "fillit.h"

void		adjustment(int id, int *j)
{
	if (g_tetr_arr[id]->arr[0][0] == '.')
	{
		if (g_tetr_arr[id]->arr[0][1] == '.')
			(*j)--;
		(*j)--;
	}
}

void		rem_figure(char **map, int id, int i, int j)
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
			{
				(map[i][j] = '.');
			}
			j++;
			t_j++;
		}
		j -= 4;
		i++;
		t_i++;
	}
}

static void	shift_n_save_crd(int *crd, int *shift, int i, int j)
{
	crd[0] = i;
	crd[1] = j;
	*shift = i * g_size;
	*shift = *shift + j;
}

int			add_figure(char **map, int id, int *shift, int *crd)
{
	int		i;
	int		j;

	i = (*shift / g_size);
	j = (*shift % g_size);
	while (i < g_size)
	{
		while (j < g_size)
		{
			if (map[i][j] == '.')
			{
				if (check_space(map, i, j, id) == 1)
				{
					write_in_map(map, i, j, id);
					shift_n_save_crd(crd, shift, i, j);
					return (1);
				}
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
