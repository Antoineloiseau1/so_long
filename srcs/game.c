/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 11:13:41 by antoine           #+#    #+#             */
/*   Updated: 2022/10/24 18:55:27 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->ptr, data->win, \
							data->img.pm_u, y * 64, x * 64);
	if (data->map[x - 1][y] == '1')
		return ;
	mlx_put_image_to_window(data->ptr, data->win, data->img.bg, y * 64, x * 64);
	if (data->map[x - 1][y] == '0')
		mlx_put_image_to_window(data->ptr, data->win, \
								data->img.pm_u, y * 64, (--data->x) * 64);
	if (data->map[x - 1][y] == 'C')
	{
		data->items--;
		data->map[x - 1][y] = '0';
		mlx_put_image_to_window(data->ptr, data->win, \
								data->img.pm_u, y * 64, (--data->x) * 64);
	}
	if (data->map[x - 1][y] == 'E')
		mlx_put_image_to_window(data->ptr, data->win, \
								data->img.pm_u, y * 64, (--data->x) * 64);
	if (data->map[x - 1][y] == 'E' && data->items == 0)
	{
		ft_printf("You finished the game with %d steps\n", data->step);
		leave();
	}
	ft_printf("Steps: %d\n", ++data->step);
}

void	move_left(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->ptr, data->win, \
							data->img.pm_l, y * 64, x * 64);
	if (data->map[x][y - 1] == '1' \
	|| (data->map[x][y - 1] == 'E' && data->items != 0))
		return ;
	mlx_put_image_to_window(data->ptr, data->win, data->img.bg, y * 64, x * 64);
	if (data->map[x][y - 1] == '0')
		mlx_put_image_to_window(data->ptr, data->win, \
								data->img.pm_l, (--data->y) * 64, x * 64);
	if (data->map[x][y - 1] == 'C')
	{
		data->items--;
		data->map[x][y - 1] = '0';
		mlx_put_image_to_window(data->ptr, data->win, \
								data->img.pm_l, (--data->y) * 64, x * 64);
	}
	if (data->map[x][y - 1] == 'E' && data->items == 0)
	{
		ft_printf("You finished the game with %d steps\n", data->step);
		leave();
	}
	ft_printf("Steps: %d\n", ++data->step);
}

void	move_right(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->ptr, data->win, \
							data->img.pm_r, y * 64, x * 64);
	if (data->map[x][y + 1] == '1' \
	|| (data->map[x][y + 1] == 'E' && data->items != 0))
		return ;
	mlx_put_image_to_window(data->ptr, data->win, data->img.bg, y * 64, x * 64);
	if (data->map[x][y + 1] == '0')
		mlx_put_image_to_window(data->ptr, data->win, \
								data->img.pm_r, ++data->y * 64, x * 64);
	if (data->map[x][y + 1] == 'C')
	{
		data->items--;
		data->map[x][y + 1] = '0';
		mlx_put_image_to_window(data->ptr, data->win, \
								data->img.pm_r, (++data->y) * 64, x * 64);
	}
	if (data->map[x][y + 1] == 'E' && data->items == 0)
	{
		ft_printf("You finished the game with %d steps\n", data->step);
		leave();
	}
	ft_printf("Steps: %d\n", ++data->step);
}

void	move_down(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->ptr, data->win, \
							data->img.pm_d, y * 64, x * 64);
	if (data->map[x + 1][y] == '1' \
	|| (data->map[x + 1][y] == 'E' && data->items != 0))
		return ;
	mlx_put_image_to_window(data->ptr, data->win, data->img.bg, y * 64, x * 64);
	if (data->map[x + 1][y] == '0')
		mlx_put_image_to_window(data->ptr, data->win, \
								data->img.pm_d, y * 64, (++data->x) * 64);
	if (data->map[x + 1][y] == 'C')
	{
		data->items--;
		data->map[x + 1][y] = '0';
		mlx_put_image_to_window(data->ptr, data->win, \
								data->img.pm_d, y * 64, (++data->x) * 64);
	}
	if (data->map[x + 1][y] == 'E' && data->items == 0)
	{
		ft_printf("You finished the game with %d steps\n", data->step);
		leave();
	}
	ft_printf("Steps: %d\n", ++data->step);
}

int	get_key(int key, t_data *data)
{
	if (key == ESC)
	{
		ft_printf("Try again next time\n");
		leave();
	}
	if (key == W || key == UP)
		move_up(data, data->x, data->y);
	if (key == A || key == LEFT)
		move_left(data, data->x, data->y);
	if (key == S || key == DOWN)
		move_down(data, data->x, data->y);
	if (key == D || key == RIGHT)
		move_right(data, data->x, data->y);
	return (0);
}
