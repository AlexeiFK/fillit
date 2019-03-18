/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 20:29:29 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/03/18 21:01:07 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

typedef struct	s_tetr
{
	char		arr[4][4];
}				t_tetr;

extern int		g_figs[26];
extern int		g_size;
extern int		g_start;
extern t_tetr	*g_tetr_arr[26];

t_tetr			*create_tetr(int id, char *str);
void			tetr_add(t_tetr *tetr, char *str);
int				is_valid(int fd);
//int				reader(int fd);
int				to_find(char *str, int i);
void			get_figures(int fd);
char			**create_map(int size);

#endif
