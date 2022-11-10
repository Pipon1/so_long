/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hefurrer <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:11:06 by hefurrer          #+#    #+#             */
/*   Updated: 2022/11/10 11:11:08 by hefurrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	<mlx.h>
#include	"../includes/so_long.h"
#include	"../libft/libft.h"
#include	<stdlib.h>

void	move_right(t_win *pl, void *pla, void *flo)
{
	mlx_put_image_to_window(pl->mlx, pl->win, flo, pl->charx, pl->chary);
	pl->charx += 16;
	mlx_put_image_to_window(pl->mlx, pl->win, pla, pl->charx, pl->chary);
}

void	move_left(t_win *pl, void *pla, void *flo)
{
	mlx_put_image_to_window(pl->mlx, pl->win, flo, pl->charx, pl->chary);
	pl->charx -= 16;
	mlx_put_image_to_window(pl->mlx, pl->win, pla, pl->charx, pl->chary);
}

void	move_up(t_win *pl, void *pla, void *flo)
{
	mlx_put_image_to_window(pl->mlx, pl->win, flo, pl->charx, pl->chary);
	pl->chary -= 16;
	mlx_put_image_to_window(pl->mlx, pl->win, pla, pl->charx, pl->chary);
}

void	move_down(t_win *pl, void *pla, void *flo)
{
	mlx_put_image_to_window(pl->mlx, pl->win, flo, pl->charx, pl->chary);
	pl->chary += 16;
	mlx_put_image_to_window(pl->mlx, pl->win, pla, pl->charx, pl->chary);
}
