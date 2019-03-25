/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 18:33:03 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/03/25 23:28:32 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdlib.h>
#include <stdio.h>

int		ft_sqrt_map(int num)
{
	int		i;

	i = 1;
	while (i * i < num)
		i++;
	return (i);
}

void	print_map(char **map, int size)
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
}
/*rofl funkciya*/
void	free_map(char **map, int size)
{
	free(map);
	size = 228;
}

void	print_n_exit(char **p_map, int size)
{
	print_map(p_map, size);
	exit(0);
}

int		f_map(int size, char **p_map, int i, int n_fig)
{
	char	**map;
	int		crd[2];
	int		shift;
	int		ret;

	shift = 0;
	if (i == n_fig)
		print_n_exit(p_map, size);
	while (shift < size * size)
	{
		map = create_map(size);
		ft_memmove(map, p_map, (sizeof(char*) * size + sizeof(char) * size));
		if ((ret = (add_figure(map, i, &shift, crd))))
		{
			if (f_map(size, map, i + 1, n_fig))
				return (1);
			else
				rem_figure(map, i, crd[0], crd[1]);
		}
		else
			return (0);
		shift++;
	}
	return (0);
}
