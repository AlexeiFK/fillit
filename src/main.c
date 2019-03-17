/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:39:06 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/03/17 19:08:21 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#include <stdio.h>

#include <unistd.h>
#include "fillit.h"
#include <fcntl.h>

int		main(int argc, char** argv)
{
	int		fd;
	int		ret;
	int		i;

	argc = 1;
	i = 0;

	fd = open(argv[1], O_RDONLY);
	printf("valid = %d\n", is_valid(fd));
	close(fd);
	ret = 0;
	fd = open(argv[1], O_RDONLY);
	get_figures(fd);
	while (i < 26)
	{
		printf("[%d] = %d\n", i, g_figs[i]);
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
