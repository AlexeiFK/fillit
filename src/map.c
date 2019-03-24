/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 18:33:03 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/03/24 20:04:03 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	ft_swap_tetr(t_tetr **x, t_tetr **y)
{
	t_tetr		*tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

int		ft_sqrt_map(int num)
{
	int		i;

	i = 1;
	while (i*i < num)
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

char	**fill_map(int size, int n_fig, int *flag) // int shift)
{
	int		i;
	int		ret;
	char	**map;

	i = 0;
	ret = 1;
	map = create_map(size);
	while (ret && (i < n_fig))
	{
		print_map(map, size);
		ret = add_figure(map, i);
		i++;
	}
	ft_putstr("_____________________\n");
	if (ret == 1)
	{
		*flag = 1;
	}
		return (map);
//	}
//	else
//	{
//		map = fill_map(size, n_fig, flag, shift);
//	}
}
