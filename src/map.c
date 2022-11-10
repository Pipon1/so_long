#include	<mlx.h>
#include	"../includes/so_long.h"
#include	"../libft/libft.h"
#include	<stdlib.h>

void	mapinit(t_win *pl)
{
	void	*fl;
	int		w;
	int		h;
	int		i;
	int		j;

	fl = mlx_xpm_file_to_image(pl->mlx, "./img/floor.xpm", &w, &h);
	i = 0;
	j = 0;
	while (j <= 16)
	{
		while (i <= 16)
		{
			mlx_put_image_to_window(pl->mlx, pl->win, fl, pl->charx, pl->chary);
			pl->charx += 16;
			i++;
		}
		i = 0;
		pl->charx = 0;
		pl->chary += 16;
		j++;
	}
	pl->charx = 0;
	pl->chary = 0;
}
