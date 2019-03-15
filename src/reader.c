/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 21:23:39 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/03/15 16:06:34 by rjeor-mo         ###   ########.fr       */
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

int		l_like(char *str, int i)
{
	if (down_right(str, i + 10) == 2)
		return (8);
	if (down_right(str, i + 10) == 1)
		return (15);
	if (str[i + 9] == '#')
		return (9);
	if (str[i + 4] == '#')
		return (13);
	return (0);
}

int		vert_like(char *str, int i)
{
	if (down_right(str, i + 5) == 2)
	{
		if (str[i + 4] == '#')
			return (11);
		if (down_right(str, i + 6) == 2)
			return (3); 
		if (down_right(str, i + 6) == 1)
			return (16);
	}
	if (down_right(str, i + 5) == 3)
		return (12);
	if (down_right(str, i + 5) == 1)
		return (l_like(str, i));
	if (str[i + 4] == '#')
	{
		if (down_right(str, i + 4) == 3)
			return (17);
		if (str[i + 3] == '#')
			return (4);
	}
	return (0);
}

int		horz_like(char *str, int i)
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
		if (down_right(str, i + 6) == 1)
			return (7);
		if (down_right(str, i + 6) == 2)
			return (19);
	}
	return (0);
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
		if (str[i + 4] == '#')
			return (18);
	}
	if (down_right(str, i) == 2)
		return (horz_like(str, i));
	if (down_right(str, i) == 1)
		return (vert_like(str, i));
	return (0);
}
