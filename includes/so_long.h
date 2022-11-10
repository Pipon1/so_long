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

typedef struct s_image
{
	void	*img;
	int		imh;
	int		imw;
}				t_image;

typedef struct s_win
{
	void	*mlx;
	void	*win;
	int		charx;
	int		chary;
	void	*imgp;
}				t_win;

void	move_right(t_win *pl, void *pla, void *flo);
void	move_left(t_win *pl, void *pla, void *flo);
void	move_up(t_win *pl, void *pla, void *flo);
void	move_down(t_win *pl, void *pla, void *flo);
#endif
