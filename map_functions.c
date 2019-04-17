/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cipmures <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:50:24 by cipmures          #+#    #+#             */
/*   Updated: 2017/02/13 17:48:25 by cipmures         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	coord_interval(int *coord, t_interval interval)
{
	coord[0] = 0;
	coord[1] = 0;
	coord[2] = interval.start.x * 5 + interval.start.y;
	coord[3] = interval.end.x * 5 + interval.end.y + 1;
}

void	map_free(char **map, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		free(map[i]);
		++i;
	}
	free(map);
}

int		map_lninit(char **map, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (!(map[i] = (char *)malloc(sizeof(char) * size)))
			return (0);
		ft_memset(map[i], '.', size);
		++i;
	}
	return (1);
}

char	**map_new(int n)
{
	char **m;

	if (!(m = (char **)malloc(sizeof(char *) * n)))
		return (NULL);
	if (!map_lninit(m, n))
		return (NULL);
	return (m);
}

void	map_show(char **map, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
			write(1, &map[i][j++], 1);
		write(1, "\n", 1);
		++i;
	}
}
