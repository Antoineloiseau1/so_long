/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_playable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:25:33 by anloisea          #+#    #+#             */
/*   Updated: 2022/10/10 17:47:26 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_playable(t_data *data, int rows)
{
	get_position(data, rows, 'P');
	ft_printf("'P is at map[%c][%c]\n", data->pos->x, data->pos->y);

	return (1);
}