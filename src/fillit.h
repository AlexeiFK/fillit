/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 20:29:29 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/03/24 20:11:11 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define VALUE_MAX 2147483647
typedef struct	s_tetr
{
	char		arr[4][4];
}				t_tetr;

extern char		**g_map;
extern int		g_figs[26];
extern int		g_size;
extern t_tetr	*g_tetr_arr[26];
extern int		g_result;

t_tetr			*create_tetr(int id, char *str, int start);
void			tetr_add(t_tetr *tetr, char *str, int start);
int				is_valid(char *filename);
int				to_find(char *str, int i);
int				get_figures(int fd);
char			**create_map(int size);
char			**fill_map(int size, int n_fig, int *flag, int shift);
void			print_map(char **map, int i);
int				add_figure(char **map, int id, int shift);
void			ft_swap_tetr(t_tetr **x, t_tetr **y);
int				ft_sqrt_map(int num);

#endif
