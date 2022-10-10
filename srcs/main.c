/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:48:12 by anloisea          #+#    #+#             */
/*   Updated: 2022/10/06 15:40:00 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_mlx	*mlx;
	t_data	*data;
	int		fd;

	if (argc != 2)
	{
		ft_printf("usage: ./so_long map\n");
		return (1);
	}


	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror(argv[1]);
		return (1);
	}


	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
		ft_printf("invalid format of map, must be .ber\n");

	
	mlx = malloc(sizeof(t_mlx));
	data = malloc(sizeof(t_data));
	data->exit = 0;
	data->items = 0;
	data->position = 0;

	data->map = get_map(fd);
	check_map(data);
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, ft_strlen(data->map[0]) * 50, tab_len(data->map) * 130, "so_long");
	mlx_loop(mlx->ptr);
	free_map(data->map);
	free(mlx);
	free(data);
	close(fd);
	return (0);

}