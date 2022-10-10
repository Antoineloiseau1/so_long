/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:49:08 by anloisea          #+#    #+#             */
/*   Updated: 2022/10/10 17:41:41 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <errno.h>
# include <mlx.h>
# include <stdio.h>

typedef struct s_mlx
{
	void		*ptr;
	void		**textures;
	void		*win;
	char		**map;
}				t_mlx;

typedef struct s_coord
{
	int	x;
	int y;
}			t_coord;

typedef struct s_data
{
	char	**map;
	int		position;
	int		exit;
	int		items;
	t_coord	*pos;
}			t_data;

void	init_data(t_data *data, int fd);
void	free_data(t_data *data);

//parsing:

char	**get_map(int fd);
int		check_map(t_data *data);
int		is_playable(t_data *data, int rows);

//utils:
int		tab_len(char **tab);
int		get_position(t_data *data, int rows, char c);

//errors:

void	error(int errnum, char *msg);
void	open_error(char *arg);
void	map_error(t_data *data, int errnum, char *msg);

#endif