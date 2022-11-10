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

int	ft_move(int keycode, t_win *pl)
{
	void	*ptrimg;
	int		w;
	int		h;
	void	*primg2;

	primg2 = mlx_xpm_file_to_image(pl->mlx, "./floor.xpm", &w, &h);
	ptrimg = mlx_xpm_file_to_image(pl->mlx, "./player.xpm", &w, &h);
	if (keycode == 124)
		move_right(pl, ptrimg, primg2);
	if (keycode == 123)
		move_left(pl, ptrimg, primg2);
	if (keycode == 126)
		move_up(pl, ptrimg, primg2);
	if (keycode == 125)
		move_down(pl, ptrimg, primg2);
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
	win.win = mlx_new_window(win.mlx, 500, 500, "So_Long");
	mlx_hook(win.win, 2, 0, ft_close, &win);
	mlx_key_hook(win.win, ft_move, &win);
	mlx_loop(win.mlx);
	return (0);
}
