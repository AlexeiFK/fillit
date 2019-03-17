/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 20:29:29 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/03/17 19:00:00 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

extern int		g_figs[26];

int				is_valid(int fd);
int				reader(int fd);
int				to_find(char *str, int i);
void			get_figures(int fd);

#endif
