/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 17:54:06 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/03/24 18:37:32 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"
#include "libft.h"

int			searcher(char *str, int *n_sharp, int *n_tetr)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			(*n_sharp)++;
		if (str[i] != '.' && str[i] != '#')
			return (0);
		i++;
	}
	(*n_tetr)++;
	return (1);
}

int			checker(int fd, int n_tetr, int n_sharp, char *str)
{
	while (get_next_line(fd, &str) == 1)
	{
		if (ft_strlen(str) == 4)
		{
			if (!searcher(str, &n_sharp, &n_tetr))
				return (0);
		}
		else
		{
			if ((n_tetr % 4) != 0)
				return (0);
			else
			{
				if (n_sharp != 4)
					return (0);
				n_tetr = 0;
				n_sharp = 0;
			}
		}
		free(str);
	}
	if (n_sharp != 4)
		return (0);
	free(str);
	return (1);
}

int			checker_plus(int fd, char *str)
{
	int		i;
	int		n_figs;

	n_figs = 1;
	i = 0;
	while (get_next_line(fd, &str) == 1)
	{
		if ((ft_strlen(str) == 4) && (i < 4))
		{
			i++;
		}
		else
		{
			if (ft_strlen(str) != 0)
			{
				return (0);
			}
			n_figs++;
			i = 0;
		}
		free(str);
	}
	free(str);
	return (n_figs);
}

int			is_valid(char *filename)
{
	char	*str;
	int		n_tetr;
	int		n_sharp;
	int		fd;
	int		ret;

	fd = open(filename, O_RDONLY);
	str = NULL;
	n_sharp = 0;
	n_tetr = 0;
	if ((checker(fd, n_tetr, n_sharp, str)) == 0)
		return (0);
	close(fd);
	fd = open(filename, O_RDONLY);
	str = NULL;
	n_sharp = 0;
	n_tetr = 0;
	ret = (checker_plus(fd, str));
	close(fd);
	return (ret);
}
