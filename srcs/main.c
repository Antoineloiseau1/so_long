/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:48:12 by anloisea          #+#    #+#             */
/*   Updated: 2022/10/14 13:55:30 by antoine          ###   ########.fr       */
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
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nso_long: ", 2);
		perror(argv[1]);
		return(1);
	}
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
		error(2, "map format must be .ber\n");
	mlx = malloc(sizeof(t_mlx));
	data = malloc(sizeof(t_data));
	init_data(data, fd);
	close(fd);
	check_map(data);
	free_data(data);
	free(mlx);
	//system("leaks so_long");
	return (0);
}
