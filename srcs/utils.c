/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:09:13 by anloisea          #+#    #+#             */
/*   Updated: 2022/10/11 14:26:34 by anloisea         ###   ########.fr       */
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

	x = 1;
	while (x < rows - 1)
	{
		y = 0;
		while (data->map[x][y])
		{
			if (data->map[x][y] == c)
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

char	**cut_endl(char **strings)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (strings[i])
	{
		j = 0;
		while (strings[i][j])
		{
			if (strings[i][j] == '\n')
			{
				tmp = strings[i];
				strings[i] = ft_substr(tmp, 0, j);
				free (tmp);
			}
			j++;
		}
		i++;
	}
	return (strings);
}
