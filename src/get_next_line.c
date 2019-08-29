/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccellado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 23:08:39 by ccellado          #+#    #+#             */
/*   Updated: 2019/08/22 23:48:57 by ccellado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

static char	*ft_conc(char *s1, char *s2)
{
	char	*conc;

	if (!s1)
		conc = ft_strdup(s2);
	else
	{
		conc = ft_strjoin(s1, s2);
		free(s1);
	}
	return (conc);
}

static void	heads_and_tails(char *curr, char **buff, char **line)
{
	char	*head;
	char	*head_temp;

	head = ft_strnew(BUFF_SIZE);
	head_temp = head;
	while (*curr != '\n')
		*head++ = *curr++;
	*head = '\0';
	*line = ft_conc(*line, head_temp);
	free(head_temp);
	curr++;
	*buff = ft_strdup(curr);
}

static char	*buff_check(char **line, char **buff)
{
	char	*temp;

	temp = *buff;
	if (ft_strchr(*buff, '\n'))
	{
		heads_and_tails(temp, buff, line);
		free(temp);
		temp = *buff;
		return (temp);
	}
	else if (temp[0] != '\0')
		*line = ft_conc(*line, *buff);
	free(temp);
	temp = *buff;
	*buff = NULL;
	return (*buff);
}

static int	find_next_line(int fd, char **buff, char **line, int *bytes)
{
	char	*curr;

	curr = ft_strnew(BUFF_SIZE);
	*line = NULL;
	if (*buff)
		if ((*buff = buff_check(line, buff)))
		{
			free(curr);
			return (1);
		}
	while ((*bytes = read(fd, curr, BUFF_SIZE)) > 0)
	{
		curr[*bytes] = '\0';
		if (ft_strchr(curr, '\n'))
		{
			heads_and_tails(curr, buff, line);
			free(curr);
			return (1);
		}
		else
			*line = ft_conc(*line, curr);
	}
	free(curr);
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char *buff[FD_HARD_LIMIT];
	int			bytes;

	bytes = 0;
	if (fd < 0 || !line || BUFF_SIZE < 0 || read(fd, 0, 0) < 0)
		return (-1);
	find_next_line(fd, &buff[fd], line, &bytes);
	if (*line)
		return (1);
	return (0);
}
