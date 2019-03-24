/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 17:51:40 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/03/24 20:10:21 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "fillit.h"

int		g_size = 0;

int		check_space(char **map, int i, int j, int id)
{
	int			t_i;
	int			t_j;
	int			flag;
	int			temp_j;

	t_i = 0;
	if (g_tetr_arr[id]->arr[0][0] == '.')
	{
		j--;
		if (g_tetr_arr[id]->arr[0][1] == '.')
			j--;
	}
	temp_j = j;
	flag = 0;
//	printf("__________________\n");
	while (t_i < 4)
	{
		t_j = 0;
	//	j -= 4;
		while (t_j < 4)
		{
//			printf("t_i = %d t_j = %d, i = %d, j = %d for id = %d\n", t_i, t_j, i, j, id);
			if (g_tetr_arr[id]->arr[t_i][t_j] != '.')
			{
//				flag++;
				if ((j + 1) > g_size)
					return (0);
				if ((i + 1) > g_size)
					return (0);
				if (map[i][j] != '.')
					return (0);
//				j++;
			}
//			if (flag)
				j++;
			t_j++;
		}
		j = temp_j;
		flag = 0;
		i++;
		t_i++;
	}
	return (1);
}

void		write_in_map(char **map, int i, int j, int id)
{
	int			t_i;
	int			t_j;

//	printf("write in i = %d, j = %d\n", i, j);
	if (g_tetr_arr[id]->arr[0][0] == '.')
	{
		if (g_tetr_arr[id]->arr[0][1] == '.')
			j--;
		j--;
	}
//	if (g_tetr_arr[id]->arr[0][1] == '.')
//		j--;
	t_i = 0;
	while (t_i < 4)
	{
		t_j = 0;
		while (t_j < 4)
		{
			if (g_tetr_arr[id]->arr[t_i][t_j] != '.')
			{	
				(map[i][j] = g_tetr_arr[id]->arr[t_i][t_j]);
			}
			j++;
			t_j++;
		}
		j -= 4;
		i++;
		t_i++;
	}
}

int			add_figure(char **map, int id, int shift)
{
	int		i;
	int		j;

	i = (shift / 4);
	j = (shift % 4);
	while (i < g_size)
	{
		while (j < g_size)
		{
			if (map[i][j] == '.')
			{
//				printf("i = %d, j = %d\n", i, j);
				if (check_space(map, i, j, id) == 1)
				{
//					printf("Check sp = 1 for %d write in i = %d j = %d\n", id, i ,j);
					write_in_map(map, i, j, id);
					return (1);
				}
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}




/*
void		get_p(int *p[], int fig)
{
	i
}

int			is_out()
{
}

int			num_to_fig(char **map, int i, int j, int fig)
{
	int		ret;
	int		p[6];

	get_p(&p, fig);
	ret = 0;
	if (((i + 1) > g_size) && ((i + 1) > g_size) && map[i + 1][j] == '.')
		if (((i + 1) > g_size) && ((i + 1) > g_size) && map[i][j + 1] == '.')
			if (((i + 1) > g_size) && ((i + 1) > g_size) && map[i + 1][j + 1] == '.')
				ret = 1;
}
*/
char		**create_map(int size)
{
	char	**map;
	int		i;
	int		j;

	g_size = size;
	map = (char**)malloc(sizeof(char*) * size);
	i = 0;
	while (i < size)
	{
		map[i] = (char*)malloc(sizeof(char) * size);
		j = 0;
		while (j < size)
		{
			map[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}
