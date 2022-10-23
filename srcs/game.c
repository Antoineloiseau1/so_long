/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 11:13:41 by antoine           #+#    #+#             */
/*   Updated: 2022/10/23 14:01:34 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void leave(t_data *data)
{
		ft_printf("You finished the game with %d steps\n", data->step);
		free_mlx(data);
		free_data(data);
		exit(0);
}

void	move_up(t_data *data)
{
	int	x = data->x;
	int	y = data->y;
	
	if (data->map[x - 1][y] == '1')
		return ;
	if (data->map[x - 1][y] == '0')
	{
		mlx_put_image_to_window(data->ptr, data->win, data->img.bg, y * 64, x * 64);
		data->x--;
		mlx_put_image_to_window(data->ptr, data->win, data->img.pm_u, y * 64, data->x * 64);
	}
	if (data->map[x - 1][y] == 'C')
	{
		mlx_put_image_to_window(data->ptr, data->win, data->img.bg, y * 64, x * 64);
		data->x--;
		data->items--;
		data->map[data->x][y] = '0';
		mlx_put_image_to_window(data->ptr, data->win, data->img.pm_u, y * 64, data->x * 64);
	}
	if (data->map[x - 1][y] == 'E')
	{
		if (data->items > 0)
			return ;
		mlx_put_image_to_window(data->ptr, data->win, data->img.bg, y * 64, x * 64);
		data->x--;
		data->exit--;
		mlx_put_image_to_window(data->ptr, data->win, data->img.pm_u, y * 64, data->x * 64);
		if (data->items == 0 && data->exit <= 0)
			leave(data);
	}
	ft_printf("Steps: %d\n", ++data->step);
}

void	move_left(t_data *data)
{
	int	x = data->x;
	int	y = data->y;
	
	if (data->map[x][y - 1] == '1')
		return ;
	if (data->map[x][y - 1] == '0')
	{
		mlx_put_image_to_window(data->ptr, data->win, data->img.bg, y * 64, x * 64);
		data->y--;
		mlx_put_image_to_window(data->ptr, data->win, data->img.pm_l, data->y * 64, x * 64);
	}
	if (data->map[x][y - 1] == 'C')
	{
		mlx_put_image_to_window(data->ptr, data->win, data->img.bg, y * 64, x * 64);
		data->y--;
		data->items--;
		data->map[x][data->y] = '0';
		mlx_put_image_to_window(data->ptr, data->win, data->img.pm_l, data->y * 64, x * 64);
	}
	if (data->map[x][y - 1] == 'E')
	{
		if (data->items > 0)
			return ;
		mlx_put_image_to_window(data->ptr, data->win, data->img.bg, y * 64, x * 64);
		data->y--;
		data->exit--;
		mlx_put_image_to_window(data->ptr, data->win, data->img.pm_l, data->y * 64, x * 64);
		if (data->items == 0 && data->exit <= 0)
			leave(data);
	}
	ft_printf("Steps: %d\n", ++data->step);
}

void	move_right(t_data *data)
{
	int	x = data->x;
	int	y = data->y;
	
	if (data->map[x][y + 1] == '1')
		return ;
	if (data->map[x][y + 1] == '0')
	{
		mlx_put_image_to_window(data->ptr, data->win, data->img.bg, y * 64, x * 64);
		data->y++;
		mlx_put_image_to_window(data->ptr, data->win, data->img.pm_r, data->y * 64, x * 64);
	}
	if (data->map[x][y + 1] == 'C')
	{
		mlx_put_image_to_window(data->ptr, data->win, data->img.bg, y * 64, x * 64);
		data->y++;
		data->items--;
		data->map[x][data->y] = '0';
		mlx_put_image_to_window(data->ptr, data->win, data->img.pm_r, data->y * 64, x * 64);
	}
	if (data->map[x][y + 1] == 'E')
	{
		if (data->items > 0)
			return ;
		mlx_put_image_to_window(data->ptr, data->win, data->img.bg, y * 64, x * 64);
		data->y++;
		data->exit--;
		mlx_put_image_to_window(data->ptr, data->win, data->img.pm_r, data->y * 64, x * 64);
		if (data->items == 0 && data->exit <= 0)
			leave(data);
	}
	ft_printf("Steps: %d\n", ++data->step);
}

void	move_down(t_data *data)
{
	int	x = data->x;
	int	y = data->y;
	
	if (data->map[x + 1][y] == '1')
		return ;
	if (data->map[x + 1][y] == '0')
	{
		mlx_put_image_to_window(data->ptr, data->win, data->img.bg, y * 64, x * 64);
		data->x++;
		mlx_put_image_to_window(data->ptr, data->win, data->img.pm_d, y * 64, data->x * 64);
	}
	if (data->map[x + 1][y] == 'C')
	{
		mlx_put_image_to_window(data->ptr, data->win, data->img.bg, y * 64, x * 64);
		data->x++;
		data->items--;
		data->map[data->x][y] = '0';
		mlx_put_image_to_window(data->ptr, data->win, data->img.pm_d, y * 64, data->x * 64);
	}
	if (data->map[x + 1][y] == 'E' && data->items > 0)
	{
		if (data->items > 0)
			return ;
		mlx_put_image_to_window(data->ptr, data->win, data->img.bg, y * 64, x * 64);
		data->x++;
		data->exit--;
		mlx_put_image_to_window(data->ptr, data->win, data->img.pm_d, y * 64, data->x * 64);
		if (data->items == 0 && data->exit <= 0)
			leave(data);
	}
	ft_printf("Steps: %d\n", ++data->step);
}

int	get_key(int key, t_data *data)
{
	if (key == ESC)
		leave(data);
	if (key == Z || key == UP)
		move_up(data);
	if (key == Q || key == LEFT)
	 	move_left(data);
	if (key == S || key == DOWN)
		move_down(data);
	if (key == D || key == RIGHT)
	 	move_right(data);
	return (0);

}

void	game(t_data *data)
{
	mlx_key_hook(data->win, get_key, data);
}