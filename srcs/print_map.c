/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:00:20 by antoine           #+#    #+#             */
/*   Updated: 2022/10/24 18:56:10 by anloisea         ###   ########.fr       */
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
				mlx_put_image_to_window(data->ptr, data->win, \
										data->img.wall, y * IMG_W, x * IMG_H);
			if (data->map[x][y] == 'P')
				mlx_put_image_to_window(data->ptr, data->win, \
										data->img.pm_r, y * IMG_W, x * IMG_H);
			if (data->map[x][y] == 'C')
				mlx_put_image_to_window(data->ptr, data->win, \
										data->img.item, y * IMG_W, x * IMG_H);
			if (data->map[x][y] == 'E')
				mlx_put_image_to_window(data->ptr, data->win, \
										data->img.exit, y * IMG_W, x * IMG_H);
			y++;
		}
		x++;
	}
}
