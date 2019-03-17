/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 17:51:40 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/03/17 19:27:28 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		**create_map(int size)
{
	int		**map;
	int		i;
	int		j;

	map = (int**)malloc(sizeof(int*) * size);
	i = 0;
	while (i < size)
	{
		map[i] = (int*)malloc(sizeof(int) * size);
		j = 0;
		map[i][j] = '.';
		i++;
	}
}
