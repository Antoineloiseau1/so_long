/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:49:08 by anloisea          #+#    #+#             */
/*   Updated: 2022/10/22 17:31:30 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <errno.h>
# include <mlx.h>
# include <stdio.h>

typedef struct s_image
{
	void	*wall;
	void	*pm_d;
	void	*pm_u;
	void	*pm_l;
	void	*pm_r;
	void	*item;
	void	*exit;
}			t_image;

typedef struct s_data
{
	char	**map;
	char	**tmp;
	t_image	img;
	void	*ptr;
	void	*win;
	int		rows;
	int		start;
	int		exit;
	int		items;
	int		x;
	int		y;
}			t_data;

void	init_data(t_data *data, char **argv);
void	free_data(t_data *data);
void	init_mlx(t_data *data);
void	free_mlx(t_data *data);

//parsing:

char	**get_map(int fd);
int		check_map(t_data *data);
int		is_playable(t_data *data);

//utils:
int		tab_len(char **tab);
int		get_position(t_data *data, char **map, char c);
char	**cut_endl(char **strings);
int		is_valid_element(char c);
char 	**copy_map(t_data *data);

//print/
void	print_background(t_data *data);
void	place_player(t_data *data);
void	print_walls(t_data *data);
void	print_map(t_data *data);

//errors:

void	error(int errnum, char *msg);
void	open_error(char *arg);
void	map_error(t_data *data, int errnum, char *msg);

#endif