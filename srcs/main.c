/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:48:12 by anloisea          #+#    #+#             */
/*   Updated: 2022/10/05 13:58:47 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_mlx	*data;
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
	data = malloc(sizeof(t_mlx));
	fd = open(argv[1], O_RDONLY);
	data->map = get_map(fd);
	check_map(data->map);
	//data->mlx = mlx_init();
	//data->win = mlx_new_window(data->mlx, 450, 300, "so_long");
	//mlx_loop(data->mlx);
	free_map(data->map);
	free(data);
	close(fd);
	return (0);

}