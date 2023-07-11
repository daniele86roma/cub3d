/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:17:05 by dfiliagg          #+#    #+#             */
/*   Updated: 2023/06/13 10:40:21 by adi-fort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	key_hook(int keycode, t_vars *vars)
{
	(void)vars;
	printf("Hello from key_hook! %d\n", keycode);
	return (0);
}

int	close_game(t_game *game)
{
	free_game(game);
	exit(0);
}


int	main(int argc, char **argv)
{
	t_game	game;
	t_vars	vars;

	(void)argc;
	(void)argv;
	init(&game);
	mlx_hook(game.mlx_win, 17, 0, close_game, &game);
	mlx_key_hook(game.mlx_win, key_hook, &vars);
	mlx_clear_window(game.mlx, game.mlx_win);
	draw_sky_floor(&game);
	mlx_loop(game.mlx);
}
