/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 20:29:29 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/03/25 23:06:39 by rjeor-mo         ###   ########.fr       */
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
extern t_tetr	*g_tetr_arr[26];

t_tetr			*create_tetr(int id, char *str, int start);
void			tetr_add(t_tetr *tetr, char *str, int start);

int				is_valid(char *filename);

int				to_find(char *str, int i);
int				get_figures(int fd);
char			**create_map(int size);
char			**fill_map(int size, int n_fig, int *flag, int shift);
int				f_map(int size, char **map, int i, int n_fig);
void			print_map(char **map, int i);
int				add_figure(char **map, int id, int *shift, int *crd);
void			rem_figure(char **map, int id, int i, int j);
int				check_space(char **map, int i, int j, int id);
void			write_in_map(char **map, int i, int j, int id);
void			adjustment(int id, int *j);
int				ft_sqrt_map(int num);
void			ft_error_msg(void);

#endif
