/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tiles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:00:20 by antoine           #+#    #+#             */
/*   Updated: 2022/10/23 13:42:27 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (data->map[x][y] == '1')
				mlx_put_image_to_window(data->ptr, data->win, data->img.wall, y * 64, x * 64);
			if (data->map[x][y] == 'P')
				mlx_put_image_to_window(data->ptr, data->win, data->img.pm_r, y * 64, x * 64);
			if (data->map[x][y] == 'C')
				mlx_put_image_to_window(data->ptr, data->win, data->img.item, y * 64, x * 64);
			if (data->map[x][y] == 'E')
				mlx_put_image_to_window(data->ptr, data->win, data->img.exit, y * 64, x * 64);
			y++;
		}
		x++;
	}
}