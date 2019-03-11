/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 21:23:39 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/03/11 22:53:39 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		down_right(char *str, int i)
{
	int		ret;

	ret = 0;
	if ((i + 1 < 20) && str[i + 1] == '#')
		ret += 2;
	if ((i + 5 < 20) && str[i + 5] == '#')
		ret += 1;
	return (ret);
}

int		to_find(char *str, int i)
{
	if (down_right(str, i) == 3)
	{
		if (down_right(str, i + 1) == 1)
			return (1);
		if (down_right(str, i + 1) == 2)
			return (2);
		if (down_right(str, i + 5) == 1)
			return (6);
	}
	if (down_right(str, i) == 2)
	{
		if (down_right(str, i + 1) == 3)
			return (10);
		if (down_right(str, i + 1) == 2)
		{
			if (down_right(str, i + 2) == 2)
				return (14);
			if (down_right(str, i + 2) == 1)
				return (5);
		}
		if (down_right(str, i + 1) == 1)
		{
			if (str[i + 4] == '#')
				return (18);
			if (down_right(str, i + 5) == 1)
				return (7);
			if (down_right(str, i + 5) == 2)
				return (19);
		}
	}
	if (down_right(str, i) == 1)
	{
		if (down_right(str, i + 5) == 2)
		{
			if (down_right(str, i + 6) == 2)
				return (3); 
			if (down_right(str, i + 6) == 1)
				return (16);
		}
		if (down_right(str, i + 5) == 3)
			return (12);
		if (down_right(str, i + 5) == 1)
		{
			if (down_right(str, i + 10) == 2)
				return (8);
			if (down_right(str, i + 10) == 1)
				return (15);
			if (str[i + 9] == '#')
				return (9);
		}
		if (str[i + 4] == '#')
		{ 
			if (down_right(str, i + 4) == 1)
				return (17);
			if (str[i + 3] == '#')
				return (4);
			if (down_right(str, i + 5) == 1)
				return (13);
		}	
	}
}

int		reader(int fd)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_strnew(20);
	read(fd, str, 20);
	if (!str)
		return (-1);
	while (str[i] != '#')
		i++;
	return (to_find(str, i));
}
