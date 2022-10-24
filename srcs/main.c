/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:48:12 by anloisea          #+#    #+#             */
/*   Updated: 2022/10/24 18:59:10 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_click(void)
{
	ft_printf("Try again next time\n");
	leave();
	return (0);
}

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
	mlx_hook(data->win, 17, 0, get_click, data);
	mlx_loop(data->ptr);
	return (0);
}
