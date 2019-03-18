/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 17:51:40 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/03/18 22:02:29 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "fillit.h"

void		add_figure(char **map, int id)
{
	int		i;
	int		j;
	int		ret;

	i = 0;
	while (i < g_size)
	{
		j = 0;
		while (j < g_size)
		{
			if (map[i][j] == '.')
			{
				if (check_space(map, i, j, id) == 1)
					write_in();
			}
			j++;
		}
		i++;
	}
}

int		check_space(char **map, int i, int j, int id)
{
	int			t_i;
	int			t_j;

	t_i = 0;
	while (t_i < 4)
	{
		t_j = 0;
		j =- 4;
		while (t_j < 4)
		{
			if (g_tetr_arr[id]->arr[t_i][t_j] != '#')
			{	
				if (map[i][j] != '.')
					return (0);
				if ((j + 1) >= g_size)
					return (0);
			}
			j++;
			t_j++;
		}
		i++;
		t_i++;
	}
	return (1);
}



/*
void		get_p(int *p[], int fig)
{
	i
}

int			is_out()
{
}

int			num_to_fig(char **map, int i, int j, int fig)
{
	int		ret;
	int		p[6];

	get_p(&p, fig);
	ret = 0;
	if (((i + 1) > g_size) && ((i + 1) > g_size) && map[i + 1][j] == '.')
		if (((i + 1) > g_size) && ((i + 1) > g_size) && map[i][j + 1] == '.')
			if (((i + 1) > g_size) && ((i + 1) > g_size) && map[i + 1][j + 1] == '.')
				ret = 1;
}
*/
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
