/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:01:47 by anloisea          #+#    #+#             */
/*   Updated: 2022/10/18 11:35:51 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_data(t_data *data, int fd)
{
	data->exit = 0;
	data->items = 0;
	data->start = 0;
	data->map = get_map(fd);
	data->map = cut_endl(data->map);
	data->rows = tab_len(data->map);
	data->tmp = copy_map(data);
}
