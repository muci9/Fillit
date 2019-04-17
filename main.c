/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cipmures <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 17:09:17 by cipmures          #+#    #+#             */
/*   Updated: 2017/02/13 17:54:10 by cipmures         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		free_buf(char *buf, int num_pcs)
{
	free(buf);
	return (num_pcs);
}

int		main(int ac, char **av)
{
	int		fd;
	t_etri	*pcs;
	int		n;

	if (ac != 2)
	{
		write(1, "Usage: ./fillit sample.fillit\n", 30);
		return (0);
	}
	if ((fd = open(av[1], O_RDONLY)) == -1)
		write(1, "error\n", 6);
	else
	{
		if (!(pcs = (t_etri *)malloc(sizeof(t_etri) * 27)))
			write(1, "error\n", 6);
		if (!(n = read_t(fd, pcs)))
			write(1, "error\n", 6);
		else if (!(solve(pcs, n)))
			write(1, "error\n", 6);
		else
			free(pcs);
	}
	close(fd);
	return (0);
}
