/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:48:10 by antoine           #+#    #+#             */
/*   Updated: 2022/10/06 16:16:43 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct	s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main()
{
	t_image pic;
	void	*mlx = mlx_init();
	void	*win = mlx_new_window(mlx, 1280, 720, "test");


	pic.img = mlx_new_image(mlx, 1280, 720);
	pic.addr = mlx_get_data_addr(pic.img, &pic.bits_per_pixel, &pic.line_length, &pic.endian);
	for (int i = 0; i < 600; i++)
	{
		my_mlx_pixel_put(&pic, 5, i + 5, 0x00FF0000);
		mlx_put_image_to_window(mlx, win, pic.img, 0, 0);
	}
	for (int i = 0; i < 600; i++)
	{
		my_mlx_pixel_put(&pic, i + 5, 5, 0x00FF0000);
		mlx_put_image_to_window(mlx, win, pic.img, 0, 0);
	}
	for (int i = 0; i < 600; i++)
	{
		my_mlx_pixel_put(&pic, 605, i + 5, 0x00FF0000);
		mlx_put_image_to_window(mlx, win, pic.img, 0, 0);
	}
	for (int i = 0; i < 601; i++)
	{
		my_mlx_pixel_put(&pic, i + 5, 605, 0x00FF0000);
		mlx_put_image_to_window(mlx, win, pic.img, 0, 0);
	}
	
	mlx_loop(mlx);
	return (0);
}