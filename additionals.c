/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additionals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cipmures <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 13:58:01 by cipmures          #+#    #+#             */
/*   Updated: 2017/02/13 17:49:11 by cipmures         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			*ft_memset(void *b, int c, size_t len)
{
	char	*myb;

	myb = (char *)b;
	while (len)
	{
		*myb = (char)c;
		++myb;
		--len;
	}
	return (b);
}

t_point			new_point(int x, int y)
{
	t_point p;

	p.x = x;
	p.y = y;
	return (p);
}

t_interval		new_interval(t_point x, t_point y)
{
	t_interval	i;

	i.start = x;
	i.end = y;
	return (i);
}

void			init(int *coord, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		if (i % 2)
			coord[i++] = 0;
		else
			coord[i++] = 3;
	}
}

t_interval		width_height_start(char *buf, t_etri *pc)
{
	int values[4];
	int i;

	init(values, 4);
	i = 0;
	while (buf[i])
	{
		if (buf[i] == '#')
		{
			if (i / 5 < values[0])
				values[0] = i / 5;
			if (i / 5 > values[1])
				values[1] = i / 5;
			if (i % 5 < values[2])
				values[2] = i % 5;
			if (i % 5 > values[3])
				values[3] = i % 5;
		}
		++i;
	}
	pc->width = values[3] - values[2] + 1;
	pc->height = values[1] - values[0] + 1;
	return (new_interval(new_point(values[0], values[2]),
				new_point(values[1], values[3])));
}
