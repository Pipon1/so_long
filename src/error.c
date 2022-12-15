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

int	maptest(t_win *m)
{
	int	size;
	int	len;

	size = ft_strlen(m->map[0]);
	len = 0;
	while (m->map[len])
		len++;
	if (len == size)
	{
		ft_printf("Error\nLa map n'est pas rectangulaire !\n");
		return (0);
	}
	if (!m->good)
	{
		ft_printf("Error\nAucun chemin trouvé !\n");
		return (0);
	}
	return (1);
}
