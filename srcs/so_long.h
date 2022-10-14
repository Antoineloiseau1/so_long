/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:49:08 by anloisea          #+#    #+#             */
/*   Updated: 2022/10/14 12:27:06 by antoine          ###   ########.fr       */
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
	int	y;
}			t_coord;

typedef struct s_data
{
	char	**map;
	int		rows;
	int		start;
	int		exit;
	int		items;
	int		x;
	int		y;
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
char	**cut_endl(char **strings);
int		is_valid_element(char c);

//errors:

void	error(int errnum, char *msg);
void	open_error(char *arg);
void	map_error(t_data *data, int errnum, char *msg);

#endif