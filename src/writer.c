/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 13:14:26 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/03/21 18:03:53 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include <stdio.h>

int		g_figs[26];
t_tetr	*g_tetr_arr[26];

int		reader(int fd, char **str, int *start)
{
	int		i;
	int		ret;
	int		ret2;

	i = 0;
	*str = ft_strnew(20);
	ret2 = read(fd, *str, 20);
	if (ret2 < 20)
		return (-1);
	if (!(*str))
		return (-1);
	while ((*str)[i] != '#')
		i++;
	ret = to_find(*str, i);
	*start = i;
	return (ret);
}

void		get_figures(int fd)
{
	int		ret;
	int		i;
	char	*str;
	int		start;

	str = NULL;
	ret = 0;
	i = 0;
	start = 0;
	while ((i < 26) && (ret != -1))
	{
		ret = reader(fd, &str, &start);
		g_figs[i] = ret;
		if (ret == 8 || ret == 10 || ret == 13 || ret == 17 || ret == 18)
			start--;
		if (ret == 6)
			start -= 2;
		g_tetr_arr[i] = create_tetr(ret, str, start);
		read(fd, str, 1);
		free(str);
		i++;
	}
}
