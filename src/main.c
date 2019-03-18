/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:39:06 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/03/18 21:15:44 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#include <stdio.h>
#include <libft.h>
#include <unistd.h>
#include "fillit.h"
#include <fcntl.h>

int		g_size = 0;

int		ft_sqrt(int num)
{
	int		i;

	i = 1;
	while (i*i < num)
		i++;
	return (i);
}

int		main(int argc, char** argv)
{
	int		fd;
	int		ret;
	int		i;
	int		j;
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
	i = 0;
	while (i < g_size)
	{
		j = 0;
		while (j < g_size)
		{
			ft_putchar(map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}



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
