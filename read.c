/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acihodar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 15:53:08 by acihodar          #+#    #+#             */
/*   Updated: 2017/02/13 17:52:36 by cipmures         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		free_stuff(char *buf, t_etri *pcs)
{
	free(pcs);
	free(buf);
	return (0);
}

void	put_piece(char *buf, t_etri *pc, char val)
{
	t_interval	interval;
	int			coord[4];

	interval = width_height_start(buf, pc);
	coord_interval(coord, interval);
	while (coord[0] < 4)
		ft_memset(pc->arr[coord[0]++], '.', 4);
	coord[0] = 0;
	while (coord[2] < coord[3])
	{
		if (buf[coord[2]] != '\n')
		{
			if (buf[coord[2]] == '#')
				pc->arr[coord[0]][coord[1]] = val;
			coord[1]++;
			if ((coord[1] + 1) > 4)
			{
				coord[0]++;
				coord[1] = 0;
			}
		}
		coord[2]++;
	}
}

int		legaturi(char *str)
{
	int block;
	int i;

	block = 0;
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if ((i + 1) < 20 && str[i + 1] == '#')
				block++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				block++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				block++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				block++;
		}
		i++;
	}
	return (block == 6 || block == 8);
}

int		valid(char *str, int count)
{
	int i;
	int blocs;

	blocs = 0;
	i = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (!(str[i] == '#' || str[i] == '.'))
				return (1);
			if (str[i] == '#' && ++blocs > 4)
				return (2);
		}
		else if (str[i] != '\n')
			return (3);
		i++;
	}
	if (count == 21 && str[20] != '\n')
		return (4);
	if (!legaturi(str))
		return (5);
	return (0);
}

int		read_t(int fd, t_etri *pcs)
{
	char	*buf;
	int		patrate;
	char	value;
	int		i;
	int		prev;

	if (!(buf = (char *)malloc(sizeof(char) * 21)))
		return (0);
	value = 'A';
	i = 0;
	while ((patrate = read(fd, buf, 21)) >= 20)
	{
		if (valid(buf, patrate))
			return (free_stuff(buf, pcs));
		put_piece(buf, &pcs[i], value);
		++value;
		++i;
		prev = patrate;
	}
	pcs[i].arr[0][0] = 0;
	if (patrate || prev != 20)
		return (free_stuff(buf, pcs));
	return (free_buf(buf, i));
}
