/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccellado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 23:14:19 by ccellado          #+#    #+#             */
/*   Updated: 2019/08/27 11:05:43 by ccellado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include "libft.h"

# define BUFF_SIZE 12
# define FD_HARD_LIMIT 4096

int		get_next_line(int fd, char **line);

#endif
