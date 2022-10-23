/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:01:47 by anloisea          #+#    #+#             */
/*   Updated: 2022/10/23 14:57:56 by antoine          ###   ########.fr       */
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
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
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
