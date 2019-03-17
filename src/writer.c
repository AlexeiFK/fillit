/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 13:14:26 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/03/17 19:07:42 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "fillit.h"
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include <stdio.h>

int		g_figs[26];

int		reader(int fd)
{
	char	*str;
	int		i;
	int		ret;
	int		ret2;

	i = 0;
	str = ft_strnew(20);
	ret2 = read(fd, str, 20);
	if (ret2 < 20)
		return (-1);
	if (!str)
		return (-1);
	while (str[i] != '#')
		i++;
	//printf("str = %s\n i = %d", str, i);
	ret = to_find(str, i);
	read(fd, str, 1);
	free(str);
	return (ret);
}

void		get_figures(int fd)
{
	int		ret;
	int		i;

	i = 0;
	ret = reader(fd);
	while ((i < 26) && (ret != -1))
	{
		g_figs[i] = ret;
		ret = reader(fd);
		i++;
	}
}

/*
void		to_free(t_fig **fig)
{
	int		i;

	i = 0;
	while (*fig[i] != NULL)
	{
		free(*fid[i]);
		i++;
	}
	free(**fig);
}

t_fig		*writer(int num)
{
	t_fig		**figs;
	int			i;

	i = 0;

	if (!(figs = (t_fig**)malloc(sizeof(t_fig*) * 27)))
		return (NULL);
	while (i < 27)
	{
		if (!(*figs[i] = (t_fig*)malloc(sizeof(t_fig))))
		{
			to_free(figs);
			return (NULL);
		}
		i++;
	}
}
*/

