/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/06/13 10:40:21 by adi-fort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_sky_floor(t_game *game)
{
	t_point	begin;
	t_point	end;
	int		y;

	begin.x = 0;
	end.x = SCREEN_W;
	y = -1;
	while (++y < (SCREEN_H / 2))
	{
		begin.y = y;
		end.y = y;
		draw_line(game, begin, end, 255);
	}
	y -= 1;
	while (++y < SCREEN_H)
	{
		begin.y = y;
		end.y = y;
		draw_line_on(&game->image, begin, end, create_trgb(0, 133, 94, 66));
	}
}
