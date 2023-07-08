/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/05/30 10:37:31 by adi-fort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// librerie standard
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <math.h>
# include <fcntl.h>

//libreria libft
# include "libft/libft.h"

//libreria grafica
# include "minilibx-linux/mlx.h"

//get_next_line
# include "get_next_line/get_next_line.h"

// risoluzione e nome
# define SCREEN_W 800
# define SCREEN_H 600
# define NAME "CUBE3D"
// Field Of View
# define FOV 0.66

// Pi
# define PI 3.14159

// passo di movimento e rotazione
# define MOVSPEED 0.1
# define ROTSPEED 0.05

// display e dati di gioco
typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
}	t_game;

// stato della telecamera (posizione, direzione, piano di proiezione)
typedef struct s_state
{
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	camx;
	double	camy;
}	t_state;

// informazioni sul raggio
typedef struct s_ray_hit
{
	double	distance;
	int		mapx;
	int		mapy;
	double	ray_dir_x;
	double	ray_dir_y;
	int		side;
}	t_ray_hit;

#endif
