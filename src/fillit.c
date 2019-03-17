/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 17:51:40 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/03/17 22:08:57 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "fillit.h"

void		add_figure(char **map, int size, int fig)
{
	int		i;
	int		j;
	int		ret;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (map[i][j] != '#')
				ret = num_to_fig(map, i, j, fig);
			if (ret == 1)
				return;
			j++;
		}
		i++;
	}
	
}

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
