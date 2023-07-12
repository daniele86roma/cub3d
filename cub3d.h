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

typedef struct s_textures {
	char	*nord;
	char	*sud;
	char	*ovest;
	char	*est;
	int		floor[3];
	int		sky[3];
}	t_textures;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

// display e dati di gioco
typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	t_textures	tex;
	t_data		image;
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

// struttura per definire un punto
typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

//init e free
void	init(t_game *game);
void	free_game(t_game *game);

//funzioni disegno
void	draw_line_on(t_data *img, t_point begin, t_point end, int color);
void	draw_line(t_game *game, t_point begin, t_point end, int color);
int		create_trgb(int t, int r, int g, int b);
void	my_mlx_pixel_put(t_data *img, int x, int y, int color);
void	draw_sky_floor(t_game *game);

#endif
