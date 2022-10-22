/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:57:05 by antoine           #+#    #+#             */
/*   Updated: 2022/10/22 14:46:09 by antoine          ###   ########.fr       */
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
	data->img.bg = mlx_xpm_file_to_image(data->ptr, "tile/bg.xpm", &width, &height);
	data->img.wall = mlx_xpm_file_to_image(data->ptr, "tile/wall.xpm", &width, &height);
	data->img.pacman = mlx_xpm_file_to_image(data->ptr, "tile/pacman.xpm", &width, &height);
	//data->img->item = mlx_xpm_file_to_image(data->ptr, "tile/item.xpm", &width, &height);
	//data->img->exit = mlx_xpm_file_to_image(data->ptr, "tile/exit.xpm", &width, &height);
}