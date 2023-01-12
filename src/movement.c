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
	if (pl->map[y][x] == '1')
		return (0);
	if (pl->map[y][x] == 'E' && pl->obj == 1)
	{
		pl->move += 1;
		ft_printf("%d\n", pl->move);
		ft_close(-1, pl);
	}
	return (1);
}

void	move_right(t_win *p, void *pla, void *flo)
{
	if (p->map[p->chary / 16][p->charx / 16] != 'E')
		mlx_put_image_to_window(p->mlx, p->win, flo, p->charx, p->chary);
	else
		mlx_put_image_to_window(p->mlx, p->win, p->img.ig, p->charx, p->chary);
	p->charx += 16;
	p->move += 1;
	ft_printf("%d\n", p->move);
	if (p->map[p->chary / 16][p->charx / 16] == 'C')
	{
		p->obj -= 1;
		p->map[p->chary / 16][p->charx / 16] = '0';
	}
	mlx_put_image_to_window(p->mlx, p->win, pla, p->charx, p->chary);
}

void	move_left(t_win *p, void *pla, void *flo)
{
	if (p->map[p->chary / 16][p->charx / 16] != 'E')
		mlx_put_image_to_window(p->mlx, p->win, flo, p->charx, p->chary);
	else
		mlx_put_image_to_window(p->mlx, p->win, p->img.ig, p->charx, p->chary);
	p->charx -= 16;
	p->move += 1;
	ft_printf("%d\n", p->move);
	if (p->map[p->chary / 16][p->charx / 16] == 'C')
	{
		p->obj -= 1;
		p->map[p->chary / 16][p->charx / 16] = '0';
	}
	mlx_put_image_to_window(p->mlx, p->win, pla, p->charx, p->chary);
}

void	move_up(t_win *p, void *pla, void *flo)
{
	if (p->map[p->chary / 16][p->charx / 16] != 'E')
		mlx_put_image_to_window(p->mlx, p->win, flo, p->charx, p->chary);
	else
		mlx_put_image_to_window(p->mlx, p->win, p->img.ig, p->charx, p->chary);
	p->chary -= 16;
	p->move += 1;
	ft_printf("%d\n", p->move);
	if (p->map[p->chary / 16][p->charx / 16] == 'C')
	{
		p->obj -= 1;
		p->map[p->chary / 16][p->charx / 16] = '0';
	}
	mlx_put_image_to_window(p->mlx, p->win, pla, p->charx, p->chary);
}

void	move_down(t_win *p, void *pla, void *flo)
{
	if (p->map[p->chary / 16][p->charx / 16] != 'E')
		mlx_put_image_to_window(p->mlx, p->win, flo, p->charx, p->chary);
	else
		mlx_put_image_to_window(p->mlx, p->win, p->img.ig, p->charx, p->chary);
	p->chary += 16;
	p->move += 1;
	ft_printf("%d\n", p->move);
	if (p->map[p->chary / 16][p->charx / 16] == 'C')
	{
		p->obj -= 1;
		p->map[p->chary / 16][p->charx / 16] = '0';
	}
	mlx_put_image_to_window(p->mlx, p->win, pla, p->charx, p->chary);
}
