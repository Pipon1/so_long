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

int	ft_close(int keycode, t_win *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		free (vars->mlx);
	}
	return (0);
}

int	main(void)
{
	t_win	win;
	t_image	img;
	char	*relative_path;

	relative_path = "./test.xpm";
	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, 1920, 1080, "Hello world!");
	img.img = mlx_xpm_file_to_image(win.mlx, relative_path, &img.imh_w, &img.img_h);
	mlx_put_image_to_window(win.mlx, win.win, img.img, 0, 0);
	mlx_put_image_to_window(win.mlx, win.win, img.img, 1000, 1000);
	mlx_hook(win.win, 2, 0, ft_close, &win);
	mlx_loop(win.mlx);
	return (0);
}
