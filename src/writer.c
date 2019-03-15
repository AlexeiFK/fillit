/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 13:14:26 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/03/15 15:46:16 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "fillit.h"
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include <stdio.h>

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
