/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tiles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:00:20 by antoine           #+#    #+#             */
/*   Updated: 2022/10/19 17:11:12 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_background(t_data *data)
{
	int	x;
	int	y;
	int	width;
	int	height;
	void *bg;

	bg = mlx_xpm_file_to_image(data->ptr, "textures/grass.xpm", &width, &height);
	x = ft_strlen(data->map[0]);
	y = data->rows;
	while(x)
	{
		y = data->rows;
		while(y)
		{
			mlx_put_image_to_window(data->ptr, data->win, bg, x * 64, y *64);
			y--;
		}
		mlx_put_image_to_window(data->ptr, data->win, bg, x * 64, y * 64);
		x--;
	}
	while(y < data->rows)
	{
		mlx_put_image_to_window(data->ptr, data->win, bg, x * 64, y *64);
		y++;
	}
}

void	place_player(t_data *data)
{
	void *player;
	int	width;
	int	height;

	get_position(data, data->map, 'P');
	player = mlx_xpm_file_to_image(data->ptr, "textures/pacman.xpm", &width, &height);
	mlx_put_image_to_window(data->ptr, data->win, player, data->y * 64, data->x * 64);
}

void	print_walls(t_data *data)
{
	int		x;
	int 	y;
	void	*wall;
	int		width;
	int		height;

	wall = mlx_xpm_file_to_image(data->ptr, "textures/wall.xpm", &width, &height);
	x = 0;
	while(data->map[x])
	{
		y = 0;
		while(data->map[x][y])
		{
			if (data->map[x][y] == '1')
				mlx_put_image_to_window(data->ptr, data->win, wall, y * 64, x * 64);
			y++;
		}
		x++;
	}
}