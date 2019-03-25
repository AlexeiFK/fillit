/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 18:33:03 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/03/25 21:18:12 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"


#include <stdlib.h>
#include <stdio.h>


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

int		f_map(int size, char **p_map, int i, int n_fig)
{
	char	**map;
//	int		flag_add;
//	int		flag_rec;
	int		crd[2];
	int		shift;
	int		ret;

	shift = 0;
	if (i == n_fig)
	{
	//	ft_putstr("Found res!\n");
		print_map(p_map, size);
		exit(0);
		return (1);
	}	
	while (shift < size*size)
	{
		map = create_map(size);
		ft_memmove(map, p_map, (sizeof(char*) * size + sizeof(char) * size));
//		printf("__________________\n");
//		print_map(map, size);
//		printf("__________________\n");
		if ((ret = (add_figure(map, i, &shift, crd))))
		{
//			i++;
//			printf("shift = %d i = %d\n", shift, i);
//			print_map(map, size);
//			ft_putstr("\n");
//			printf("next is comming\n");
			if (f_map(size, map, i + 1, n_fig))
				return (1);
			else
			{
				rem_figure(map, i, crd[0], crd[1]);
//				print_map(map, size);
//				printf("ubral %d\n", i);
			}
			//	return (0);
		}
		else
		{
//			printf("%d ne postavil\n", i);
//			ft_putnbr(ret);
		//	free(map); //norm free
			return (0);
		}
		shift++;
	}
	return (0);
}

char	**fill_map(int size, int n_fig, int *flag, int shift)
{
	int		i;
	int		ret;
	char	**map;

	i = 0;
	ret = 1;
	map = create_map(size);
//	ft_putstr("_______XXXXXXXXX______\n");
//	f_map(size, map , i);
//	ft_putstr("_______XXXXXXXXXX_____\n");
//	return NULL;
	while (ret && (i < n_fig))
	{
//		ft_putstr("xxxxxxxxxxxxxxxxx\n");
//		print_map(map, size);
		ret = add_figure(map, i, &shift, NULL);
		i++;
		shift = 0;
	}
//	ft_putstr("_____________________\n");
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
