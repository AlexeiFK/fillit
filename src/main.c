/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:39:06 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/03/25 20:54:07 by rjeor-mo         ###   ########.fr       */
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

void	permute(int size, int i, int length, int *res, int shift) 
{
	int			j;
	char		**map;
	int			flag;
	static int	value = VALUE_MAX;
	int			tmp_value;
//	int			shift;

//	shift = 0;
	if (length == i)
	{
		flag = 0;
//		while (shift < size*size)
//		{
			map = fill_map(size, length, &flag, shift);
			shift++;
//			if (flag)
//				break ;
//		}
		if (flag)
		{
			*res = 1;
//			ft_putchar('\n');
			//print_map(map, size);
			tmp_value = get_result(map, size);
				print_map(map, size);
//				getchar();
				ft_putstr("_____________\n");
				exit(0);
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
		permute(size, i + 1, length, res, shift);
		ft_swap_tetr(&g_tetr_arr[i], &g_tetr_arr[j]);
		j++;
	}
	return ;
}

int		main(int argc, char** argv)
{
	int		fd;
	int		i;
//	int		j;
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
	if (is_valid(argv[1]) == 0)
	{
		ft_putstr("error");
		exit(0);
	}
	fd = open(argv[1], O_RDONLY);
	i = get_figures(fd);
	if (i != is_valid(argv[1]))
	{
		ft_putstr("error");
		exit(0);
	}
//	j = 0;
//	while ((j < 26) && (g_figs[j] > 0))
//	{
//		printf("[%d] = %d\n", j, g_figs[j]);
//		j++;
//	}
	size = ft_sqrt_map(i * 4);
	tmp = i;
/*	int		shift;
	while (res == 0)
	{
		shift = 0;
		map = create_map(size);
		while (shift < size*size)
		{
			permute(size, 0, i, &res, shift);
			shift++;
		}
		tmp++;
		size = ft_sqrt_map(tmp * 4);
	}
	*/
//	map = create_map(size);
//	int crd[2];
	int ret1;

	ret1 = 0;
	while (!ret1)
	{
		map = create_map(size);
		ret1 = f_map(size, map, 0, i);
		tmp++;
		size = ft_sqrt_map(tmp * 4);
	}
//	add_figure(map, 0, 0, crd);
//	add_figure(map, 1, 0, crd);
//	print_map(g_map, size);
//	rem_figure(map, 1, crd[0], crd[1]);
//	print_map(g_map, size);
	close(fd);
	return (0);
}
