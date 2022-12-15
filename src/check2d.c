/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hefurrer <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 10:24:04 by hefurrer          #+#    #+#             */
/*   Updated: 2022/12/06 10:37:06 by hefurrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"../libft/libft.h"
#include	"../includes/so_long.h"
#include	<stdlib.h>

void	destroymap(t_win *m)
{
	int	i;

	i = 0;
	while (m->map[i])
	{
		free (m->map[i]);
		i++;
	}
}

int	objectnbr(char **tab)
{
	int	i;
	int	j;
	int	res;
	int	size;

	size = ft_strlen(tab[0]);
	i = 0;
	res = 0;
	while (tab[i])
	{
		j = 0;
		while (j < size)
		{
			if (tab[i][j] == 'C' || tab[i][j] == 'E')
				res++;
			j++;
		}
		i++;
	}
	return (res);
}

void	check2d(t_win *m, int x, int y)
{
	if (m->map[y][x] == '1' || m->map[y][x] == 'Z')
		return ;
	m->map[y][x] = 'Z';
	check2d(m, x, y - 1);
	check2d(m, x + 1, y);
	check2d(m, x, y + 1);
	check2d(m, x - 1, y);
}
