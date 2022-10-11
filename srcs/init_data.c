/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:01:47 by anloisea          #+#    #+#             */
/*   Updated: 2022/10/11 13:51:03 by anloisea         ###   ########.fr       */
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
}
