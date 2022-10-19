/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_playable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:25:33 by anloisea          #+#    #+#             */
/*   Updated: 2022/10/19 12:43:42 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_collectible(char c)
{
	if (c == '0' || c == 'E' || c == 'C')
		return (1);
	return (0);
}

void	move_to_next_safe(t_data *data, int x, int y)
{
	if (is_collectible(data->tmp[x - 1][y]) == 1)
		data->x--;
	else if (is_collectible(data->tmp[x + 1][y]) == 1)
		data->x++;
	else if (is_collectible(data->tmp[x][y - 1]) == 1)
		data->y--;
	else if (is_collectible(data->tmp[x][y + 1]) == 1)
		data->y++;
	else
		return ;
}

int	is_safe(t_data *data, int x, int y)
{
	int	ways;

	ways = 0;
	if (is_collectible(data->tmp[x - 1][y]))
		ways++;
	if (is_collectible(data->tmp[x][y - 1]))
		ways++;
	if (is_collectible(data->tmp[x + 1][y]))
		ways++;
	if (is_collectible(data->tmp[x][y + 1]))
		ways++;
	if (ways > 1)
	{
		data->tmp[x][y] = 'P';
		move_to_next_safe(data, x, y);
	}
	else
	{
		data->tmp[x][y] = '1';
		move_to_next_safe(data, x, y);
	}
	return (ways);
}

int	is_playable(t_data *data)
{
	int	x;
	int	y;

	get_position(data, data->tmp, 'P');
	while (1)
	{	
		x = data->x;
		y = data->y;
		if (data->tmp[x][y] == 'C')
			data->items--;
		if (data->tmp[x][y] == 'E')
			data->exit--;
		if (data->exit == 0 && data->items == 0)
			return (1);
		if (is_safe(data, x, y) == 0)
			if (get_position(data, data->tmp, 'P') == 0)
				break ;
	}
	return (0);
}
