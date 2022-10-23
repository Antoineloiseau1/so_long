/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:57:05 by antoine           #+#    #+#             */
/*   Updated: 2022/10/23 15:00:14 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_mlx(t_data *data)
{
	int	len;
	int	width;
	int	height;

	len = ft_strlen(data->map[0]);
	data->ptr = mlx_init();
	data->win = mlx_new_window(data->ptr, len * 64, data->rows * 64, "so_long");
	data->img.wall = mlx_xpm_file_to_image(data->ptr, "tile/wall.xpm", \
											&width, &height);
	data->img.bg = mlx_xpm_file_to_image(data->ptr, "tile/bg.xpm", \
											&width, &height);
	data->img.pm_u = mlx_xpm_file_to_image(data->ptr, "tile/pm_u.xpm", \
											&width, &height);
	data->img.pm_d = mlx_xpm_file_to_image(data->ptr, "tile/pm_d.xpm", \
											&width, &height);
	data->img.pm_l = mlx_xpm_file_to_image(data->ptr, "tile/pm_l.xpm", \
											&width, &height);
	data->img.pm_r = mlx_xpm_file_to_image(data->ptr, "tile/pm_r.xpm", \
											&width, &height);
	data->img.item = mlx_xpm_file_to_image(data->ptr, "tile/item.xpm", \
											&width, &height);
	data->img.exit = mlx_xpm_file_to_image(data->ptr, "tile/exit.xpm", \
											&width, &height);
}
