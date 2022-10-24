/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:24:37 by anloisea          #+#    #+#             */
/*   Updated: 2022/10/24 15:58:33 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_data(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	i = 0;
	while (data->tmp[i])
	{
		free(data->tmp[i]);
		i++;
	}
	free(data->tmp);
	free(data->map);
	free(data);
}

void	free_mlx(t_data *data)
{
	mlx_destroy_image(data->ptr, data->img.exit);
	mlx_destroy_image(data->ptr, data->img.wall);
	mlx_destroy_image(data->ptr, data->img.item);
	mlx_destroy_image(data->ptr, data->img.pm_u);
	mlx_destroy_image(data->ptr, data->img.pm_d);
	mlx_destroy_image(data->ptr, data->img.pm_l);
	mlx_destroy_image(data->ptr, data->img.pm_r);
	mlx_destroy_image(data->ptr, data->img.bg);
	mlx_destroy_window(data->ptr, data->win);
	free(data->ptr);
}
