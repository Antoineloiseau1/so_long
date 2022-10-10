/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:09:13 by anloisea          #+#    #+#             */
/*   Updated: 2022/10/10 17:53:03 by anloisea         ###   ########.fr       */
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


int	get_position(t_data *data, int rows, char c)
{
	int	x;
	int	y;

	x = 0;
	while (x < rows)
	{
		y = 0;
		while (data->map[x][y] != '\n' || data->map[x][y] != 0)
		{
			printf("%c", data->map[x][y]);
			if (data->map[x][y] == c)
			{
				data->pos->x = x;
				data->pos->y = y;
				return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}
