/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsuter <gsuter@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:41:44 by gsuter            #+#    #+#             */
/*   Updated: 2024/04/18 15:41:44 by gsuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"
# include "../libft/incs/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>

# define ASSET_WIDTH 32

enum map_stuff{
	BACKGROUND,
	COIN,
	DOOR,
	WALL,
	PLAYER
};

typedef struct s_map
{
	size_t	x;
	size_t	y;
	size_t	width;
	size_t	height;
	size_t	np;
	size_t	ne;
	size_t	nc;
	size_t	exit_x;
	size_t	exit_y;
	char	**map;
	char	**clone_map;
}		t_map;

typedef struct s_assets
{
	void	*img[5];
	int		h;
}		t_assets;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;

}		t_mlx;

typedef struct s_glob
{
	t_map			map;
	t_mlx			data;
	t_assets		assets;
}		t_glob;

/*----------FILL_MAP---------*/
void	ft_parse_the_map(char *argv, t_map *map);
char	*str_join_map(char *src, char *map_buf, t_map *map);

/*-------MAP_CHECKER----------*/
void	ft_check_map(t_map *map);
void	ft_check_token(char **mapper, t_map *map, int flag);
void	ft_find_player_pos(t_map *map, int x, int y);
void	ft_check_token_good(t_map *map, int token[3], int flag);
void	check_invalid_element(char **str, t_map *map);

/*-------MAP_VALIDITY----------*/
void	ft_clone_map(t_map *map);
void	ft_map_is_available(t_map *map);

/*-----------MLX---------------*/
void	ft_start_mini(t_glob *glob);
/*-----------MLX_IMG-----------*/
void	ft_init_img(t_glob *glob);
void	a_load(t_glob *glob);
/*-----------MLX_MOVES-----------*/
void	ft_z_move(t_map *map, t_glob *glob);
void	ft_s_move(t_map *map, t_glob *glob);
void	ft_d_move(t_map *map, t_glob *glob);
void	ft_q_move(t_map *map, t_glob *glob);
/*-----------MLX_RULES-----------*/
void	ft_coin_count(t_map *map, t_glob *glob);
void	ft_door(t_map *map, t_glob *glob);


/*-----------EXIT-------------*/
void	ft_free_map(t_map *map);
void	ft_destroy(t_mlx *data);
void	ft_exit(t_map *map, char *msg);
void	ft_exit_success(t_glob *glob, char *msg, int flag);

#endif