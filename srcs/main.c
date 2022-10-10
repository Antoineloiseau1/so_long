/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:48:12 by anloisea          #+#    #+#             */
/*   Updated: 2022/10/10 13:10:58 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_mlx	*mlx;
	t_data	*data;
	int		fd;

	if (argc != 2)
		error(1, "usage: ./so_long map\n");
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
		error(2, "map format must be .ber\n");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		open_error(argv[1]);
	mlx = malloc(sizeof(t_mlx));
	data = malloc(sizeof(t_data));
	init_data(data, fd);
	check_map(data);
	mlx = malloc(sizeof(t_mlx));
	free_data(data);
	free(mlx);
	close(fd);
	return (0);
}
