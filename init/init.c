/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/06/13 10:40:21 by adi-fort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init(t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window (game->mlx, 800, 600, NAME);
	game->image.img = mlx_new_image(game->mlx, SCREEN_W, SCREEN_H);
	game->image.addr = mlx_get_data_addr(game->image.img,
			&game->image.bits_per_pixel, &game->image.line_length,
			&game->image.endian);
}
