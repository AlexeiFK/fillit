/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:39:06 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/03/15 15:40:24 by rjeor-mo         ###   ########.fr       */
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

	argc = 1;

	fd = open(argv[1], O_RDONLY);
	printf("valid = %d\n", is_valid(fd));
	close(fd);
	ret = 0;
	fd = open(argv[1], O_RDONLY);
	while (ret != -1)
	{
		ret = reader(fd);
		printf("reader = %d\n", ret);
	}
	close(fd);

	return (0);
}
