/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_to_fig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 18:11:06 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/03/20 17:22:46 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include <stdio.h>

void		tetr_add(t_tetr *new, char *str)
{
	int			i;
	int			j;
	int			k;
	int			mv;
	int			sh;
	static char c = 'A';

	i = 0;
	sh = 0;
	mv = (g_start % 5) + 1;
//	printf("MV == %d\n", mv);
	k = g_start;
	while (i < 4 && (sh < 4))
	{
		j = 0;
		while (j < 4 && (sh < 4))
		{
			if (str[k] == '\n')
			{
				k += mv;
				if (mv != 1)
					i++;
					j = 0;
			}
			if (str[k] == '#')
			{
				sh++;
				new->arr[i][j] = c;
			}
			k++;
			j++;
		}
		i++;
	}
	c++;
}

t_tetr		*create_tetr(int id, char *str)
{
	t_tetr		*new;
	int			i;
	int			j;

//	ft_putstr("____init_______\n");
	if (!(new =(t_tetr*)malloc(sizeof(t_tetr))))
		return (NULL);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			new->arr[i][j] = '.';
			j++;
		}
		i++;
	}
	i = 0;
/*	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putchar(new->arr[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	*/
//	ft_putstr("____init_______\n");
//	ft_putnbr(g_start);
//	ft_putstr("______str______\n");
//	ft_putstr(str);
//	ft_putstr("_____res_______\n");
	id = 0;
	tetr_add(new, str);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putchar(new->arr[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
	return (new);
}
