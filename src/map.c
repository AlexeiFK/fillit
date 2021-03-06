/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 18:33:03 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/08/29 19:08:13 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdlib.h>

int		ft_sqrt_map(int num)
{
	int		i;

	i = 1;
	while (i * i < num)
		i++;
	return (i);
}

int		print_map(char **map, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_putchar(map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	return (1);
}

int		free_map(char **map, int size, int ret)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (map[i] != NULL)
			free(map[i]);
		i++;
	}
	free(map);
	return (ret);
}

char	**mapcpy(char **map, int size)
{
	int		i;
	int		j;
	char	**new;

	new = create_map(size);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			new[i][j] = map[i][j];
			j++;
		}
		i++;
	}
	return (new);
}

int		f_map(t_fi *f, char **p_map, int i, int n_fig)
{
	char	**map;
	int		shift;
	int		ret;
	int		size;

	size = f->size;
	shift = 0;
	if (i == n_fig)
		return (print_map(p_map, size));
	while (shift < size * size)
	{
		map = mapcpy(p_map, size);
		if ((ret = (add_figure(map, i, &shift, f))))
		{
			if (f_map(f, map, i + 1, n_fig))
				return (free_map(map, size, 1));
			free_map(map, size, 0);
		}
		else
		{
			return (free_map(map, size, 0));
		}
		shift++;
	}
	return (free_map(map, size, 0));
}
