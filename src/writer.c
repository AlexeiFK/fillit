/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 13:14:26 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/03/21 17:44:41 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include <stdio.h>

int		g_figs[26];
int		g_start;
t_tetr	*g_tetr_arr[26];

int		reader(int fd, char **str)
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
	g_start = i;
	return (ret);
}

void		get_figures(int fd)
{
	int		ret;
	int		i;
	char	*str;

	str = NULL;
	ret = 0;
	i = 0;
	while ((i < 26) && (ret != -1))
	{
		ret = reader(fd, &str);
		g_figs[i] = ret;
		if (ret == 8 || ret == 10 || ret == 13 || ret == 17 || ret == 18)
			g_start--;
		if (ret == 6)
			g_start -= 2;
		g_tetr_arr[i] = create_tetr(ret, str);
		read(fd, str, 1);
		free(str);
		i++;
	}
}
