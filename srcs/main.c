/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:48:12 by anloisea          #+#    #+#             */
/*   Updated: 2022/10/03 18:05:18 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (1);
	t_mlx	*data;
	int		fd;

	data = malloc(sizeof(t_mlx));
	fd = open(argv[1], O_RDONLY);
	data->map = get_map(fd);
	ft_display_tab(data->map);
	//data->mlx = mlx_init();
	//data->win = mlx_new_window(data->mlx, 450, 300, "so_long");
	//mlx_loop(data->mlx);
	free(data);
	free(data->map);
	close(fd);
	return (0);

}