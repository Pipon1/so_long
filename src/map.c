/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hefurrer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:27:58 by hefurrer          #+#    #+#             */
/*   Updated: 2022/12/15 10:28:01 by hefurrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	<mlx.h>
#include	"../includes/so_long.h"
#include	"../libft/libft.h"
#include	<stdlib.h>
#include	<fcntl.h>

void	findplayer(char **map, t_win *pl)
{
	int	i;
	int	j;
	int	size;

	j = 0;
	i = 0;
	size = ft_strlen(map[0]);
	while (map[i])
	{
		while (j < size)
		{
			if (map[i][j] == 'P')
			{
				pl->charx = j;
				pl->chary = i;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	draw(int x, int y, t_win *pl, int td)
{
	if (td == 1)
		mlx_put_image_to_window(pl->mlx, pl->win, pl->img->imgf, x, y);
	else if (td == 2)
		mlx_put_image_to_window(pl->mlx, pl->win, pl->img->imgw, x, y);
	else if (td == 3)
	{
		mlx_put_image_to_window(pl->mlx, pl->win, pl->img->imgf, x, y);
		mlx_put_image_to_window(pl->mlx, pl->win, pl->img->imgp, x, y);
		pl->charx = x;
		pl->chary = y;
	}
	else if (td == 4)
		mlx_put_image_to_window(pl->mlx, pl->win, pl->img->imge, x, y);
	else if (td == 5)
		mlx_put_image_to_window(pl->mlx, pl->win, pl->img->imgc, x, y);
}

void	drawmap(char **map, t_win *pl)
{
	int	i;
	int	j;
	int	size;

	size = ft_strlen(map[0]);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (j < size)
		{
			if (map[i][j] == '0')
				draw(j * 16, i * 16, pl, 1);
			if (map[i][j] == '1')
				draw(j * 16, i * 16, pl, 2);
			if (map[i][j] == 'P')
				draw(j * 16, i * 16, pl, 3);
			if (map[i][j] == 'E')
				draw(j * 16, i * 16, pl, 4);
			if (map[i][j] == 'C')
				draw(j * 16, i * 16, pl, 5);
			j++;
		}
		i++;
	}
}

char	**readmap(int fd)
{
	char	*buffer;
	int		check;
	char	**map;

	buffer = malloc(sizeof(char) * 500);
	if (!buffer)
		return (0);
	check = read(fd, buffer, 500);
	if (check == -1)
		return (0);
	map = ft_split(buffer, '\n');
	if (!map)
		return (0);
	free(buffer);
	return (map);
}

char	**mapinit(t_win *pl)
{
	int		fd;

	fd = open("./map/map.ber", O_RDONLY);
	if (fd == -1)
		return (0);
	pl->map = readmap(fd);
	if (!pl->map)
		return (0);
	close(fd);
	findplayer(pl->map, pl);
	pl->obj = objectnbr(pl->map);
	check2d(pl, pl->charx, pl->chary, 0);
	if (pl->good)
	{
		fd = open("./map/map.ber", O_RDONLY);
		pl->map = readmap(fd);
		if (!pl->map)
			return (0);
		drawmap(pl->map, pl);
		return (pl->map);
	}
	return (0);
}
