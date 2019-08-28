/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 20:29:29 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/03/26 21:23:04 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

typedef struct	s_tetr
{
	char		arr[4][4];
}				t_tetr;

typedef struct	s_fi
{
	int		figs[26];
	int		size;
	t_tetr		*tetr_arr[26];
	int		id;
}		t_fi;

t_tetr			*create_tetr(char *str, int start);
void			tetr_add(t_tetr *tetr, char *str, int start);
void			free_figures(int n, t_fi *f);

int				is_valid(char *filename);

int				read_til_end(int fd, char *str);
int				to_find(char *str, int i);
int				get_figures(int fd, t_fi *f);
char			**create_map(int size);
char			**fill_map(int size, int n_fig, int *flag, int shift);
int				f_map(t_fi *f, char **map, int i, int n_fig);
int				print_map(char **map, int i);
int				free_map(char **map, int size, int ret);
int				add_figure(char **map, int id, int *shift, t_fi *f);
void			rem_figure(char **map, int id, int i, int j);
int				check_space(char **map, int i, int j, t_fi *f);
void			write_in_map(char **map, int i, int j, t_fi *f);
void			adjustment(int id, int *j, t_fi *f);
int				ft_sqrt_map(int num);
void			ft_error_msg(void);

#endif
