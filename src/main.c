/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:39:06 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/03/26 21:45:50 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <libft.h>
#include <unistd.h>
#include "fillit.h"
#include <fcntl.h>

void			ft_error_msg(void)
{
	ft_putstr("error");
	exit(0);
}

static void		usage_msg(void)
{
	ft_putstr("usage: ./fillit source_file");
	exit(0);
}

static int		get_figs_from_file(char *filename)
{
	int		n_figs;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error_msg();
	n_figs = get_figures(fd);
	close(fd);
	return (n_figs);
}

static void		resolve_fillit(int n_figs)
{
	int		ret;
	int		size_of_map;
	int		size_of_side;
	char	**map;

	ret = 0;
	size_of_map = ft_sqrt_map(n_figs * 4);
	size_of_side = n_figs;
	while (!ret)
	{
		map = create_map(size_of_map);
		ret = f_map(size_of_map, map, 0, n_figs);
		free_map(map, size_of_map, 0);
		if (ret == 1)
			free_figures(26);
		size_of_side++;
		size_of_map = ft_sqrt_map(size_of_side * 4);
	}
}

int				main(int argc, char **argv)
{
	int		n_figs;

	if (argc != 2)
		usage_msg();
	if (is_valid(argv[1]) == 0)
		ft_error_msg();
	n_figs = get_figs_from_file(argv[1]);
	if (n_figs != is_valid(argv[1]))
	{
		free_figures(26);
		ft_error_msg();
	}
	resolve_fillit(n_figs);
	return (0);
}
