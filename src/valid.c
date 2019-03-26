/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 17:54:06 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/03/26 21:32:13 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"
#include "libft.h"
#include "fillit.h"

static int	searcher(char *str, int *n_sharp, int *n_tetr)
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

static int	check_error(int ret, char *str)
{
	free(str);
	if (ret == -1)
		ft_error_msg();
	return (0);
}

int			checker(int fd, int n_tetr, int n_sharp, char *str)
{
	int ret;

	while ((ret = get_next_line(fd, &str)) == 1)
	{
		if (ft_strlen(str) == 4)
		{
			if (!searcher(str, &n_sharp, &n_tetr))
				return (check_error(0, str));
		}
		else if ((n_tetr % 4) != 0)
			return (check_error(0, str));
		else
		{
			if (n_sharp != 4)
				return (check_error(0, str));
			n_tetr = 0;
			n_sharp = 0;
		}
		free(str);
	}
	if (n_sharp != 4)
		return (check_error(0, str));
	check_error(ret, str);
	return (1);
}

int			checker_plus(int fd, char *str)
{
	int		i;
	int		n_figs;
	int		ret;

	n_figs = 1;
	i = 0;
	while ((ret = get_next_line(fd, &str)) == 1)
	{
		if ((ft_strlen(str) == 4) && (i < 4))
		{
			i++;
		}
		else
		{
			if (ft_strlen(str) != 0)
			{
				return (check_error(0, str));
			}
			n_figs++;
			i = 0;
		}
		free(str);
	}
	check_error(ret, str);
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
		return (read_til_end(fd, str));
	close(fd);
	fd = open(filename, O_RDONLY);
	ret = (checker_plus(fd, str));
	if (ret == 0)
		read_til_end(fd, str);
	close(fd);
	return (ret);
}
