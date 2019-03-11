/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:39:06 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/03/11 22:51:21 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#include <stdio.h>


#include "fillit.h"
#include <fcntl.h>

int		main(int argc, char** argv)
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	printf("valid = %d", is_valid(fd));
	close(argv[1]);

	fd = open(argv[1], O_RDONLY);
	printf("reader = %d", reader(fd));
	close(argv[1]);

	return (0);
}