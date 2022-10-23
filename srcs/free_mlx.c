/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:18:48 by antoine           #+#    #+#             */
/*   Updated: 2022/10/23 14:57:11 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_mlx(t_data *data)
{
	mlx_destroy_window(data->ptr, data->win);
	mlx_destroy_image(data->ptr, data->img.exit);
	mlx_destroy_image(data->ptr, data->img.wall);
	mlx_destroy_image(data->ptr, data->img.item);
	mlx_destroy_image(data->ptr, data->img.pm_u);
	mlx_destroy_image(data->ptr, data->img.pm_d);
	mlx_destroy_image(data->ptr, data->img.pm_l);
	mlx_destroy_image(data->ptr, data->img.pm_r);
	mlx_destroy_image(data->ptr, data->img.bg);
	free(data->ptr);
}
