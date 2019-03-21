/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:39:06 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/03/21 20:10:05 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <stdlib.h>
#include <stdio.h>
#include <libft.h>
#include <unistd.h>
#include "fillit.h"
#include <fcntl.h>

int		g_result = 0;
char	**g_map = NULL;

int		get_result(char **map, int size)
{
	int	i;
	int	j;
	int	val;

	i = 0;
	val = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (map[i][j] != '.')
			{
				val = val + j;
				val = val + i;
			}
			j++;
		}
		i++;
	}
	return (val);
}

void	permute(int size, int i, int length, int *res) 
{
	int			j;
	char		**map;
	int			flag;
	static int	value = VALUE_MAX;
	int			tmp_value;

	if (length == i)
	{
		flag = 0;
		map = fill_map(size, length, &flag);
		if (flag)
		{
			*res = 1;
//			ft_putchar('\n');
			//print_map(map, size);
			tmp_value = get_result(map, size);
			if (value > tmp_value)
			{
			//	print_map(map, size);
				value = tmp_value;
				g_map = map;
			//	printf("VALUE = %d\n", get_result(map, size));
			}
		}
		return ;
	}
	j = i;
	while (j < length)
	{
		ft_swap_tetr(&g_tetr_arr[i], &g_tetr_arr[j]);
		permute(size, i + 1, length, res);
		ft_swap_tetr(&g_tetr_arr[i], &g_tetr_arr[j]);
		j++;
	}
	return ;
}

int		main(int argc, char** argv)
{
	int		fd;
	int		i;
	int		res;
	int		size;
	int		tmp;
	char	**map;

	res = 0;
	if (argc != 2)
	{
		ft_putstr("usage:\n");
		return (0);
	}
	i = 0;
	fd = open(argv[1], O_RDONLY);
//	printf("valid = %d\n", is_valid(fd));
	close(fd);
	fd = open(argv[1], O_RDONLY);
	get_figures(fd);
	while ((i < 26) && (g_figs[i] > 0))
		i++;
	size = ft_sqrt_map(i * 4);
	tmp = i;
	while (res == 0)
	{
		map = create_map(size);
		permute(size, 0, i, &res);
		tmp++;
		size = ft_sqrt_map(tmp * 4);
	}
	print_map(g_map, size);
//	printf("RES = %d\n", res);
	close(fd);
	return (0);
}
