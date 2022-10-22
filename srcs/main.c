/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:48:12 by anloisea          #+#    #+#             */
/*   Updated: 2022/10/22 17:35:41 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	leave(int key, t_data *data)
{
	if (key == 65307)
	{
		free_mlx(data);
		free_data(data);
		exit(0);
	}
	return (0);	
}

int	main(int argc, char *argv[])
{
	t_data	*data;

	if (argc != 2)
		error(1, "usage: ./so_long MAP\n");
	data = malloc(sizeof(t_data));
	if (!data)
		return(EXIT_FAILURE);
	init_data(data, argv);
	init_mlx(data);
	print_map(data);
	ft_printf("map printed\n");
	mlx_key_hook(data->win, leave, data);
	mlx_loop(data->ptr);
	free_data(data);
	free(data->win);
	free(data->ptr);
	return (0);
}
