/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:09:13 by anloisea          #+#    #+#             */
/*   Updated: 2022/10/24 15:01:25 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_position(t_data *data, char **map, char c)
{
	int	x;
	int	y;

	x = 1;
	while (x < data->rows - 1)
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == c)
			{
				data->x = x;
				data->y = y;
				return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}

int	is_valid_element(char c)
{
	if (c == '0' || c == '1' || c == 'E' || c == 'P' || c == 'C')
		return (1);
	else
		return (0);
}

char	**copy_map(t_data *data)
{
	int		i;
	char	**copy;

	copy = malloc((data->rows + 1) * sizeof(*copy));
	if (!copy)
		return (NULL);
	i = 0;
	while (data->map[i])
	{
		copy[i] = ft_strdup(data->map[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
