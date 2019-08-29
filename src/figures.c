/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 22:23:35 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/08/29 19:03:39 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		adjustment(int id, int *j, t_fi *f)
{
	if (f->tetr_arr[id]->arr[0][0] == '.')
	{
		if (f->tetr_arr[id]->arr[0][1] == '.')
			(*j)--;
		(*j)--;
	}
}

static void	shift_n_save_crd(int *shift, int size, int i, int j)
{
	*shift = i * size;
	*shift = *shift + j;
}

int			add_figure(char **map, int id, int *shift, t_fi *f)
{
	int		i;
	int		j;

	i = (*shift / f->size);
	j = (*shift % f->size);
	f->id = id;
	while (i < f->size)
	{
		while (j < f->size)
		{
			if (map[i][j] == '.')
			{
				if (check_space(map, i, j, f) == 1)
				{
					write_in_map(map, i, j, f);
					shift_n_save_crd(shift, f->size, i, j);
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
