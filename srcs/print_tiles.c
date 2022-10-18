/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tiles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:00:20 by antoine           #+#    #+#             */
/*   Updated: 2022/10/18 15:59:00 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_background(t_data *data, t_mlx *mlx)
{
	int	x;
	int	y;
	int	width;
	int	height;
	void *bg;

	bg = mlx_xpm_file_to_image(mlx->ptr, "textures/grass.xpm", &width, &height);
	x = ft_strlen(data->map[0]);
	y = data->rows;
	while(x)
	{
		y = data->rows;
		while(y)
		{
			mlx_put_image_to_window(mlx->ptr, mlx->win, bg, x * 64, y *64);
			y--;
		}
		mlx_put_image_to_window(mlx->ptr, mlx->win, bg, x * 64, y * 64);
		x--;
	}
	while(y < data->rows)
	{
		mlx_put_image_to_window(mlx->ptr, mlx->win, bg, x * 64, y *64);
		y++;
	}
}

void	place_player(t_data *data, t_mlx *mlx)
{
	void *player;
	int	width;
	int	height;

	get_position(data, data->map, 'P');
	player = mlx_xpm_file_to_image(mlx->ptr, "textures/link.xpm", &width, &height);
	mlx_put_image_to_window(mlx->ptr, mlx->win, player, data->y * 76, data->x * 64);
}