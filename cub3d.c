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

void	fake_parser(t_game *game, int argc, char **argv)
{
	game->tex.sky[0] = 135;
	game->tex.sky[1] = 206;
	game->tex.sky[2] = 235;
	game->tex.floor[0] = 133;
	game->tex.floor[1] = 94;
	game->tex.floor[2] = 66;
	(void)argc;
	(void)argv;
}


int	main(int argc, char **argv)
{
	t_game	game;
	t_vars	vars;

	fake_parser(&game, argc, argv);
	init(&game);
	mlx_hook(game.mlx_win, 17, 0, close_game, &game);
	mlx_key_hook(game.mlx_win, key_hook, &vars);
	//mlx_clear_window(game.mlx, game.mlx_win);
	draw_sky_floor(&game);
	mlx_put_image_to_window(game.mlx, game.mlx_win, game.image.img, 0, 0);
	mlx_loop(game.mlx);
}
