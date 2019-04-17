/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cipmures <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 15:29:55 by cipmures          #+#    #+#             */
/*   Updated: 2017/02/13 17:51:55 by cipmures         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

typedef struct	s_etri
{
	char	arr[4][4];
	int		height;
	int		width;
}				t_etri;

typedef	struct	s_point
{
	int		x;
	int		y;
}				t_point;

typedef	struct	s_nterval
{
	t_point	start;
	t_point end;
}				t_interval;

t_point			new_point(int x, int y);
t_interval		new_interval(t_point x, t_point y);
void			coord_interval(int *coord, t_interval interv);
void			init(int *coord, int n);
int				free_stuff(char *buf, t_etri *pcs);
int				free_buf(char *buf, int pcs_num);
void			put_piece(char *buf, t_etri *pc, char val);
int				legaturi(char *str);
int				valid(char *str, int count);
void			*ft_memset(void *area, int ch, size_t n);
int				read_t(int fd, t_etri *pcs);
t_interval		width_height_start(char *buf, t_etri *pc);
void			pos_valid(t_etri pc, int x, int y, char **map);
void			pos_reset(t_etri pc, int x, int y, char **map);
int				valid_pos(t_etri pc, int x, int y, char **map);
int				backt(t_etri *pcs, int k, char **map, int size);
int				solve(t_etri *pcs, int n);
void			map_show(char **m, int n);
void			map_free(char **m, int n);
int				map_lninit(char **map, int n);
char			**map_new(int n);

#endif
