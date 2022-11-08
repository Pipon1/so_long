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

typedef struct s_image {
	void	*img;
	int		img_h;
	int		imh_w;
}				t_image;

typedef struct s_win {
	void	*mlx;
	void	*win;
}				t_win;
#endif
