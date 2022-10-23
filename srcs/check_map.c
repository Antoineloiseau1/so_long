/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:41:28 by antoine           #+#    #+#             */
/*   Updated: 2022/10/23 14:50:46 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_closed(char **map, int rows)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (map[0][i])
	{
		if (map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (map[rows -1][i])
	{
		if (map[rows - 1][i] != '1')
			return (0);
		i++;
	}
	while (j < rows -1)
	{
		if (map[j][0] != '1' || map[j][ft_strlen(map[j]) - 1] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	is_rectangular(char **map, int rows)
{
	int	i;

	i = 1;
	while (i < rows)
	{
		if (ft_strlen(map[0]) != ft_strlen(map[i]))
			return (0);
		i++;
	}
	return (1);
}	

int	check_items(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
				data->start++;
			if (data->map[i][j] == 'E')
				data->exit++;
			if (data->map[i][j++] == 'C')
				data->items++;
		}
		i++;
	}
	if (data->start != 1)
		return (0);
	if (data->exit != 1)
		return (0);
	if (data->items < 1)
		return (0);
	return (1);
}

int	check_for_extra(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (is_valid_element(data->map[i][j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_map(t_data *data)
{
	if (check_for_extra(data))
		map_error(data, 8, "map contains undesired element(s)\n");
	if (is_closed(data->map, data->rows) == 0)
		map_error(data, 5, "map must be closed\n");
	if (is_rectangular(data->map, data->rows) == 0)
		map_error(data, 4, "map must be rectangular\n");
	if (check_items(data) == 0)
		map_error(data, 6, "map must contains 1 'E', 1 'P' & at least 1 'C'\n");
	if (is_playable(data) == 0)
		map_error(data, 7, "map is not playable\n");
	return (0);
}
