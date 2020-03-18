/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaniche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 01:15:01 by khaniche          #+#    #+#             */
/*   Updated: 2019/04/15 01:15:05 by khaniche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <stdio.h>
# include <fcntl.h>

int					g_n;

typedef	struct		s_tetri
{
	int				x[4];
	int				y[4];
	int				l;
	int				h;
	char			letter;
	struct s_tetri	*next;
}					t_tetri;

typedef	struct		s_point
{
	int				x;
	int				y;
}					t_point;

char				**ft_read(int fd, t_tetri *tetr);
char				ft_map(char *buff, t_tetri **tetr);
char				ft_figure(char *buff, int *position);
int					sqrt_size(int size);
void				place_x_y(t_tetri *tetr, int i);
void				cut_tetr(t_tetri *tetr);
char				**alloc_map(int size);
void				free_map(char **map);
int					b_tracker(char **map, t_tetri *tetr, t_point *point,
					int size);
void				get_h_l(t_tetri *tetr);

#endif
