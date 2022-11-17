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

int	collision(t_win *pl, int d)
{
	int	x;
	int	y;

	x = pl->charx;
	y = pl->chary;
	if (d == 1)
		x += 16;
	if (d == 2)
		x -= 16;
	if (d == 3)
		y -= 16;
	if (d == 4)
		y += 16;
	x /= 16;
	y /= 16;
	ft_printf("x : %d\n", x);
	ft_printf("y : %d\n", y);
	ft_printf("orix : %d\n", pl->charx / 16);
	ft_printf("oriy : %d\n", pl->chary / 16);
	ft_printf("case testé : %c\n", pl->map[y][x]);
	if (pl->map[y][x] == '1')
		return (0);
	return (1);
}

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
