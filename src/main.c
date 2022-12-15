/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hefurrer <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:24:04 by hefurrer          #+#    #+#             */
/*   Updated: 2022/11/08 10:37:06 by hefurrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	<mlx.h>
#include	"../includes/so_long.h"
#include	"../libft/libft.h"
#include	<stdlib.h>

int	ft_close(int keycode, t_win *p)
{
	if (keycode == 53 || (p->map[p->chary / 16][p->charx / 16] == 'E' \
		&& p->obj == 1) || (keycode == -1))
	{
		mlx_destroy_image(p->mlx, p->img->imgp);
		mlx_destroy_image(p->mlx, p->img->imgf);
		mlx_destroy_image(p->mlx, p->img->ig);
		mlx_destroy_image(p->mlx, p->img->imgc);
		mlx_destroy_image(p->mlx, p->img->imgw);
		mlx_destroy_window(p->mlx, p->win);
		destroymap(p);
		exit (0);
	}
	return (0);
}

void	mapsize(t_win *pl)
{
	int	size;
	int	len;

	size = ft_strlen(pl->map[0]);
	len = 0;
	while (pl->map[len])
		len++;
	pl->win = mlx_new_window(pl->mlx, size * 16, len * 16, "So_Long");
}

int	ft_move(int keycode, t_win *p)
{
	if (p->obj == 1 && p->map[p->chary / 16][p->charx / 16] == 'E')
		ft_close(0, p);
	if (keycode == 2 && collision(p, 1))
		move_right(p, p->img->imgp, p->img->imgf);
	if (keycode == 0 && collision(p, 2))
		move_left(p, p->img->imgp, p->img->imgf);
	if (keycode == 13 && collision(p, 3))
		move_up(p, p->img->imgp, p->img->imgf);
	if (keycode == 1 && collision(p, 4))
		move_down(p, p->img->imgp, p->img->imgf);
	return (0);
}

int	main(void)
{
	t_win	win;
	int		h;
	int		w;

	win.charx = 0;
	win.chary = 0;
	win.good = 0;
	win.move = 0;
	win.mlx = mlx_init();
	win.img->imgf = mlx_xpm_file_to_image(win.mlx, "./img/floor.xpm", &w, &h);
	win.img->imgp = mlx_xpm_file_to_image(win.mlx, "./img/player.xpm", &w, &h);
	win.img->imgw = mlx_xpm_file_to_image(win.mlx, "./img/wall.xpm", &w, &h);
	win.img->ig = mlx_xpm_file_to_image(win.mlx, "./img/exit.xpm", &w, &h);
	win.img->imgc = mlx_xpm_file_to_image(win.mlx, "./img/coin.xpm", &w, &h);
	mapinit(&win);
	win.obj = objectnbr(win.map);
	mapsize(&win);
	drawmap(win.map, &win);
	if (!maptest(&win))
		ft_close(-1, &win);
	mlx_hook(win.win, 2, 0, ft_close, &win);
	mlx_key_hook(win.win, ft_move, &win);
	mlx_loop(win.mlx);
	pause ();
	return (0);
}
