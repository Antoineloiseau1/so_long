/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:48:12 by anloisea          #+#    #+#             */
/*   Updated: 2022/10/23 16:34:42 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_data	*data;

	if (argc != 2)
		error(1, "usage: ./so_long MAP\n");
	data = malloc(sizeof(t_data));
	if (!data)
		return (EXIT_FAILURE);
	init_data(data, argv);
	init_mlx(data);
	print_map(data);
	check_items(data);
	get_position(data, data->map, 'P');
	data->map[data->x][data->y] = '0';
	mlx_key_hook(data->win, get_key, data);
	mlx_loop(data->ptr);
	return (0);
}
