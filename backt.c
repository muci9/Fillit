/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cipmures <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 17:49:01 by cipmures          #+#    #+#             */
/*   Updated: 2017/02/13 17:49:06 by cipmures         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	pos_valid(t_etri pc, int x, int y, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < pc.height)
	{
		j = 0;
		while (j < pc.width)
		{
			if (pc.arr[i][j] != '.')
				map[x + i][y + j] = pc.arr[i][j];
			++j;
		}
		++i;
	}
}

void	pos_reset(t_etri pc, int x, int y, char **map)
{
	int i;
	int j;

	i = 0;
	while (i < pc.height)
	{
		j = 0;
		while (j < pc.width)
		{
			if (map[x + i][y + j] == pc.arr[i][j] && pc.arr[i][j] != '.')
				map[x + i][y + j] = '.';
			++j;
		}
		++i;
	}
}

int		valid_pos(t_etri pc, int x, int y, char **map)
{
	int		i;
	int		j;

	i = 0;
	while (i < pc.height)
	{
		j = 0;
		while (j < pc.width)
		{
			if (pc.arr[i][j] != '.' && map[x + i][y + j] != '.')
				return (0);
			++j;
		}
		++i;
	}
	pos_valid(pc, x, y, map);
	return (1);
}

int		backt(t_etri *pcs, int k, char **map, int size)
{
	int x;
	int y;

	x = 0;
	if (pcs[k].arr[0][0] == 0)
		return (1);
	while (x < size - pcs[k].height + 1)
	{
		y = 0;
		while (y < size - pcs[k].width + 1)
		{
			if (valid_pos(pcs[k], x, y, map))
			{
				if (backt(pcs, k + 1, map, size))
					return (1);
				else
					pos_reset(pcs[k], x, y, map);
			}
			++y;
		}
		++x;
	}
	return (0);
}

int		solve(t_etri *pcs, int n)
{
	char	**map;
	int		size;

	size = 2;
	while (size * size < n * 4)
		++size;
	if (!(map = map_new(size)))
		return (0);
	while (!backt(pcs, 0, map, size))
	{
		map_free(map, size);
		++size;
		if (!(map = map_new(size)))
			return (0);
	}
	map_show(map, size);
	return (1);
}
