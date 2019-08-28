/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 13:14:26 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/03/26 21:50:35 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h"
#include <stdio.h>

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
	if (ret == 0)
		free(*str);
	*start = i;
	return (ret);
}

int		read_til_end(int fd, char *str)
{
	free(str);
	while (get_next_line(fd, &str) > 0)
		free(str);
	free(str);
	return (0);
}

void	free_figures(int n, t_fi *f)
{
	int		i;

	i = 0;
	while (i < n)
	{
		free(f->tetr_arr[i]);
		i++;
	}
}

int		get_figures(int fd, t_fi *f)
{
	int		ret;
	int		i;
	char	*str;
	int		start;

	str = NULL;
	ret = 0;
	i = 0;
	start = 0;
	while ((i <= 26) && (ret != -1))
	{
		if ((ret = reader(fd, &str, &start)) == 0)
			break ;
		f->figs[i] = ret;
		if (ret == 8 || ret == 10 || ret == 13 || ret == 17 || ret == 18)
			start--;
		if (ret == 6)
			start -= 2;
		f->tetr_arr[i] = create_tetr(str, start);
		read(fd, str, 1);
		free(str);
		i++;
	}
	return (i - 1);
}
