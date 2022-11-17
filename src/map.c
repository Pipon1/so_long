#include	<mlx.h>
#include	"../includes/so_long.h"
#include	"../libft/libft.h"
#include	<stdlib.h>
#include	<fcntl.h>

void	draw(int x, int y, t_win *pl, int td)
{
	void	*img;
	void	*img2;
	void	*imgp;
	int		h;
	int		w;

	img = mlx_xpm_file_to_image(pl->mlx, "./img/floor.xpm", &w, &h);
	img2 = mlx_xpm_file_to_image(pl->mlx, "./img/wall.xpm", &w, &h);
	imgp = mlx_xpm_file_to_image(pl->mlx, "./img/player.xpm", &w, &h);
	if (td == 1)
		mlx_put_image_to_window(pl->mlx, pl->win, img, x, y);
	else if (td == 2)
		mlx_put_image_to_window(pl->mlx, pl->win, img2, x, y);
	else if (td == 3)
	{
		mlx_put_image_to_window(pl->mlx, pl->win, img, x, y);
		mlx_put_image_to_window(pl->mlx, pl->win, imgp, x, y);
		pl->charx = x;
		pl->chary = y;
	}
}

int	drawmap(char **map, t_win *pl)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < 5)
	{
		while (j < 13)
		{
			if (map[i][j] == '0')
				draw(j * 16, i * 16, pl, 1);
			if (map[i][j] == '1')
				draw(j * 16, i * 16, pl, 2);
			if (map[i][j] == 'P')
				draw(j * 16, i * 16, pl, 3);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
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
	char	**map;

	fd = open("./map/map.ber", O_RDONLY);
	if (fd == -1)
		return (0);
	map = readmap(fd);
	if (!map)
		return (0);
	drawmap(map, pl);
	return (map);
}
