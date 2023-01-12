/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hefurrer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 07:37:53 by hefurrer          #+#    #+#             */
/*   Updated: 2023/01/12 07:37:56 by hefurrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	<mlx.h>
#include	"../includes/so_long.h"
#include	"../libft/libft.h"

t_win	varini(void)
{
	t_win	win;
	int		h;
	int		w;

	win.charx = 0;
	win.chary = 0;
	win.good = 0;
	win.move = 0;
	win.win = 0;
	win.mlx = mlx_init();
	win.img.imgf = mlx_xpm_file_to_image(win.mlx, "./img/floor.xpm", &w, &h);
	win.img.imgp = mlx_xpm_file_to_image(win.mlx, "./img/player.xpm", &w, &h);
	win.img.imgw = mlx_xpm_file_to_image(win.mlx, "./img/wall.xpm", &w, &h);
	win.img.ig = mlx_xpm_file_to_image(win.mlx, "./img/exit.xpm", &w, &h);
	win.img.imgc = mlx_xpm_file_to_image(win.mlx, "./img/coin.xpm", &w, &h);
	return (win);
}
