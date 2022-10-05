/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:41:28 by antoine           #+#    #+#             */
/*   Updated: 2022/10/05 13:50:55 by antoine          ###   ########.fr       */
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

int	check_map(char **map)
{
	int	rows;

	rows = tab_len(map);
	if (is_rectangular(map, rows) == 0)
		ft_printf("map is not rectangular\n");
	if (is_closed(map, rows) == 0)
		ft_printf("map is not closed\n");
	return (0);
}