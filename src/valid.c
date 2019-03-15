/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 17:54:06 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/03/15 14:21:11 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int			is_valid(int fd)
{
	char	*str;
	int		n_tetr;
	int		n_sharp;

	str = NULL;
	n_sharp = 0;
	n_tetr = 0;
	return (checker(fd, n_tetr, n_sharp, str));
}
