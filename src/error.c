/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hefurrer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:21:06 by hefurrer          #+#    #+#             */
/*   Updated: 2023/01/09 09:06:21 by hefurrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"../includes/so_long.h"
#include	"../libft/libft.h"
#include	<mlx.h>

int	testobj(int size, int len, t_win *m, t_error *er)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < len)
		{
			if (m->map[j][i] == 'E')
				er->g1 = 1;
			if (m->map[j][i] == 'C')
				er->g2 = 1;
			if (m->map[j][i] == 'P')
				er->g3 = 1;
			j++;
		}
		i++;
	}
	return (1);
}

int	obj_isgood(t_win *m, int size, int len)
{
	t_error	er;

	er.g1 = 0;
	er.g2 = 0;
	er.g3 = 0;
	size = ft_strlen(m->map[0]);
	while (m->map[len])
		len++;
	testobj(size, len, m, &er);
	if (er.g1 == 1 && er.g2 == 1 && er.g3 == 1)
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
	if (!checkline(size, len, m))
		writen = ft_printf("Error\nLa map n'est pas rectangulaire !\n");
	else if (!checkborder(m, 0, 0, 1))
		writen = ft_printf("Error\nLa bordure n'est pas composé de murs !\n");
	else if (!m->good)
		writen = ft_printf("Error\nAucun chemin trouvé !\n");
	else if (!obj_isgood(m, size, len))
		writen = ft_printf("Error\nIl manque un ou plusieurs objets !\n");
	else if (!charcheck(size, len, m))
		writen = ft_printf("Error\nCharactères interdit trouvés !\n");
	else if (!duplicate(size, len, m))
		writen = ft_printf("Error\nMultiple occurence du même charactère!\n");
	if (writen != 0)
		return (0);
	return (1);
}
