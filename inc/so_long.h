#ifndef SO_LONG_H
#define SO_LONG_H

#include "../mlx_linux/mlx.h"
#include "../mlx_linux/mlx_int.h"
#include "../libft/incs/libft.h"

typedef struct s_map
{
	size_t	x;
	size_t	y;
	char	**map;
}		t_map;


/*----------FILL_MAP---------*/
void	ft_parse_the_map(char *argv, t_map *map);
char	*str_join_map(char *src, char *map_buf, t_map *map);

/*-------MAP_CHECKER----------*/
void	ft_check_map(t_map *map);
void	ft_find_player_pos(t_map *map, int x, int y);
void	ft_check_token_is_good(t_map *map, int E, int P, int C);
/*-------MAP_VALIDITY----------*/
void	ft_map_is_available(char **str, t_map *map);

/*-----------EXIT-------------*/
void	ft_exit(t_map *map, char *msg);
void	ft_free_things(t_map *map);


#endif