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

int	ft_move(int keycode, t_win *p)
{
	int		w;
	int		h;
	void	*primg2;

	primg2 = mlx_xpm_file_to_image(p->mlx, "./img/floor.xpm", &w, &h);
	p->imgp = mlx_xpm_file_to_image(p->mlx, "./img/player.xpm", &w, &h);
	if (keycode == 124 && collision(p, 1))
		move_right(p, p->imgp, primg2);
	if (keycode == 123 && collision(p, 2))
		move_left(p, p->imgp, primg2);
	if (keycode == 126 && collision(p, 3))
		move_up(p, p->imgp, primg2);
	if (keycode == 125 && collision(p, 4))
		move_down(p, p->imgp, primg2);
	return (0);
}

int	ft_close(int keycode, t_win *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit (0);
	}
	return (0);
}

int	main(void)
{
	t_win		win;
	char		*relative_path;

	relative_path = "./player.xpm";
	win.charx = 0;
	win.chary = 0;
	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, 512, 512, "So_Long");
	win.map = mapinit(&win);
	mlx_hook(win.win, 2, 0, ft_close, &win);
	mlx_key_hook(win.win, ft_move, &win);
	mlx_loop(win.mlx);
	return (0);
}
