/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:39:06 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/03/20 22:34:12 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <stdlib.h>
#include <stdio.h>
#include <libft.h>
#include <unistd.h>
#include "fillit.h"
#include <fcntl.h>

int		g_size = 0;

void	printArray()
{
	int	i;

	i = 0;
	while ((i < 26) && (g_figs[i] > 0))
	{
		printf("[%d] = %d\n", i, g_figs[i]);
		i++;
	}
}

void	ft_swap(t_tetr **x, t_tetr **y)
{
	t_tetr		*tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

void	permute(int i, int length) 
{
	int		j;
	char	**map;
	int		flag;

	if (length == i)
	{
		flag = 0;
		map = fill_map(g_size, length, &flag);
		if (flag)
		{
			ft_putchar('\n');
			print_map(map, g_size);
	//		exit(1);
		}
//		ft_putnbr(flag);
//		ft_putchar('\n');
		return ;
	}
	j = i;
	while (j < length)
	{
		ft_swap(&g_tetr_arr[i], &g_tetr_arr[j]);
		permute(i + 1,length);
		ft_swap(&g_tetr_arr[i], &g_tetr_arr[j]);
		j++;
	}
	return ;
}

int		ft_sqrt(int num)
{
	int		i;

	i = 1;
	while (i*i < num)
		i++;
	return (i);
}

//char	**fill_map(char **map)

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

char	**fill_map(int size, int n_fig, int *flag)
{
	int		i;
	int		ret;
	char	**map;

	i = 0;
	ret = 1;
	map = create_map(size);
	while (ret && (i < n_fig))
	{
		ret = add_figure(map, i);
		i++;
	}
//	printf("ret = %d i = %d\n",ret, i );
	if (ret == 1)
		*flag = 1;
	return (map);
}

int		main(int argc, char** argv)
{
	int		fd;
	int		ret;
	int		i;
//	int		j;
	int		size;
	char	**map;

	argc = 1;
	i = 0;
	size = 5;

	fd = open(argv[1], O_RDONLY);
	printf("valid = %d\n", is_valid(fd));
	close(fd);
	ret = 0;
	fd = open(argv[1], O_RDONLY);
	get_figures(fd);
	while ((i < 26) && (g_figs[i] > 0))
	{
		printf("[%d] = %d\n", i, g_figs[i]);
		i++;
	}
	g_size = ft_sqrt(i * 4);
	map = create_map(g_size);
	permute(0, i);
//	map = fill_map(g_size);
//	ft_swap(&(g_tetr_arr[0]), &(g_tetr_arr[2]));
	//printf("______________\n");
	//printArray();
/*	i = 0;
	permute(0, 3);
	while (add_figure(map, i))
	{
		print_map(map, g_size);
		printf("\n");
		i++;
	}
	*/
//		print_map(map, g_size);


/*	
	while (ret != -1)
	{
		ret = reader(fd);
		printf("reader = %d\n", ret);
	}
	*/
	close(fd);

	return (0);
}
