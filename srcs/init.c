/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:01:47 by anloisea          #+#    #+#             */
/*   Updated: 2022/10/25 12:00:40 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_data(t_data *data, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nso_long: ", 2);
		perror(argv[1]);
		exit(EXIT_FAILURE);
	}
	if (ft_strnstr(argv[1], ".ber\0", ft_strlen(argv[1])) == NULL)
		error(2, "map format must be .ber\n");
	data->exit = 0;
	data->items = 0;
	data->start = 0;
	data->step = 0;
	data->map = get_map(fd);
	close(fd);
	data->map = cut_endl(data->map);
	data->rows = tab_len(data->map);
	data->tmp = copy_map(data);
	check_map(data);
}

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
