/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hefurrer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:21:06 by hefurrer          #+#    #+#             */
/*   Updated: 2022/12/15 13:21:09 by hefurrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"../includes/so_long.h"
#include	"../libft/libft.h"

int	obj_isgood(t_win *m, int size, int len, int g1, int g2, int g3)
{
	int	i;
	int	j;

	i = 0;
	size = ft_strlen(m->map[0]);
	while (m->map[len])
		len++;
	while (i < size)
	{
		j = 0;
		while (j < len)
		{
			if (m->map[j][i] == 'E')
				g1 = 1;
			if (m->map[j][i] == 'C')
				g2 = 1;
			if (m->map[j][i] == 'P')
				g3 = 1;
			j++;
		}
		i++;
	}
	if (g1 == 1 && g2 == 1 && g3 == 1)
		return (1);
	return (0);
}

int	checkborder(t_win *m, int size, int len, int good)
{
	int	i;

	i = 0;
	size = ft_strlen(m->map[0]);
	while (m->map[len])
		len++;
	while (i < size)
	{
		if (m->map[0][i] != '1' || m->map[len - 1][i] != '1')
			good = 0;
		i++;
	}
	i = 0;
	while (i < len)
	{
		if (m->map[i][0] != '1')
			good = 0;
		if (m->map[i][size - 1] != '1')
			good = 0;
		i++;
	}
	if (good == 0)
		return (0);
	return (1);
}

int	maptest(t_win *m)
{
	int	size;
	int	len;
	int	writen;

	size = ft_strlen(m->map[0]);
	len = 0;
	writen = 0;
	while (m->map[len])
		len++;
	if (len == size)
		writen = ft_printf("Error\nLa map n'est pas rectangulaire !\n");
	else if (!checkborder(m, 0, 0, 1))
		writen = ft_printf("Error\nLa bordure n'est pas composé de murs !\n");
	else if (!m->good)
		writen = ft_printf("Error\nAucun chemin trouvé !\n");
	else if (!obj_isgood(m, size, len, 0, 0, 0))
		writen = ft_printf("Error\nIl manque un ou plusieurs objets !\n");
	if (writen != 0)
		return (0);
	return (1);
}
