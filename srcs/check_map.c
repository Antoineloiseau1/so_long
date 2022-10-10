/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:41:28 by antoine           #+#    #+#             */
/*   Updated: 2022/10/06 15:08:36 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	tab_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	is_closed(char **map, int rows)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while(map[0][i] != '\n' && map[0][i])
	{
		if (map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while(map[rows - 1][i] != '\n' && map[rows -1][i])
	{
		if (map[rows - 1][i] != '1')
			return (0);
		i++;
	}
	while (j < rows -1)
	{
		if (map[j][0] != '1' || map[j][ft_strlen(map[j]) -2] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	is_rectangular(char **map, int rows)
{
	int	i;

	i = 1;
	if (ft_strlen(map[0]) - 1 != ft_strlen(map[rows - 1]))
		return (0);
	while (i < rows - 1)
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
				data->position++;
			if (data->map[i][j] == 'E')
				data->exit++;
			if (data->map[i][j] == 'C')
				data->items++;
			j++;
		}
		i++;
	}
	if (data->position != 1)
		return (0);
	if (data->exit != 1)
		return (0);
	if (data->items < 1)
		return (0);
	return (1);
}

int	check_map(t_data *data)
{
	int	rows;

	rows = tab_len(data->map);
	if (is_rectangular(data->map, rows) == 0)
		ft_printf("map is not rectangular\n");
	if (is_closed(data->map, rows) == 0)
		ft_printf("map is not closed\n");
	if (check_items(data) == 0)
		ft_printf("must contain at least one of each: START, EXIT, ITEM\n");
	return (0);
}