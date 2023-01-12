/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hefurrer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 08:01:45 by hefurrer          #+#    #+#             */
/*   Updated: 2023/01/12 08:01:47 by hefurrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"../libft/libft.h"
#include	"../includes/so_long.h"

int	errorcheck(int er, t_win *w)
{
	if (er != 2)
	{
		ft_printf("Error\nParamètres non valide !\n");
		return (0);
	}
	if (!checkname(w))
	{
		ft_printf("Error\nExtensions non valide !\n");
		return (0);
	}
	return (1);
}

int	checkline(int size, int len, t_win *m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < len)
	{
		while (m->map[j][i])
			i++;
		if (i != size)
			return (0);
		i = 0;
		j++;
	}
	return (1);
}

int	charcheck(int size, int len, t_win *m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < len)
	{
		while (i < size)
		{
			if (m->map[j][i] != '1' && m->map[j][i] != '0' && \
			m->map[j][i] != 'E' && m->map[j][i] != 'P' && m->map[j][i] != 'C' \
			&& m->map[j][i] != '\n')
				return (0);
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

int	duplicate(int size, int len, t_win *m)
{
	int	i;
	int	j;
	int	good;
	int	good2;

	i = 0;
	j = 0;
	good = 0;
	good2 = 0;
	while (j < len)
	{
		while (i < size)
		{
			if (m->map[j][i] == 'P')
				good++;
			if (m->map[j][i] == 'E')
				good2++;
			if (good2 > 1 || good > 1)
				return (0);
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}
