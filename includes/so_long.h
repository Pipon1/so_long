/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hefurrer <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:31:51 by hefurrer          #+#    #+#             */
/*   Updated: 2022/11/08 11:31:58 by hefurrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H
# include	<mlx.h>

typedef struct s_image
{
	void	*imgp;
	void	*imgf;
	void	*ig;
	void	*imgc;
	void	*imgw;
}				t_image;

typedef struct s_win
{
	void	*mlx;
	void	*win;
	int		charx;
	int		chary;
	char	**map;
	int		good;
	int		obj;
	int		move;
	t_image	*img;
}				t_win;

void	move_right(t_win *pl, void *pla, void *flo);
void	move_left(t_win *p, void *pla, void *flo);
void	move_up(t_win *p, void *pla, void *flo);
void	move_down(t_win *p, void *pla, void *flo);
char	**mapinit(t_win *pl, int fd);
int		collision(t_win *pl, int d);
void	check2d(t_win *m, int x, int y);
int		objectnbr(char **tab);
void	drawmap(char **map, t_win *pl);
void	destroymap(t_win *m);
int		maptest(t_win *m);
int		checkborder(t_win *m, int size, int len, int good);
int		ft_close(int keycode, t_win *p);

#endif
