/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 13:14:26 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/03/15 13:17:05 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>
#include <fcntl.h>

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
