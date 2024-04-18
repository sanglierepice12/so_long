#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"
# include "../libft/incs/libft.h"
/*# include <X11/X.h>
# include <X11/keysym.h>*/
#include <X11/X.h>
#include <X11/keysym.h>
# include <fcntl.h>

typedef struct s_map
{
	size_t	x;
	size_t	y;
	size_t	len;
	size_t	np;
	size_t	ne;
	size_t	nc;
	char	**map;
	char	**clone_map;
}		t_map;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_glob
{
	t_map	map;
	t_mlx	data;
}  t_glob;


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
void	ft_start_mini(t_glob glob);

/*-----------EXIT-------------*/
void	ft_free_map(t_map *map);
void	ft_destroy(t_mlx *data);
void	ft_exit(t_map *map, char *msg);
void	ft_exit_success(t_glob *glob, char *msg, int flag);

#endif