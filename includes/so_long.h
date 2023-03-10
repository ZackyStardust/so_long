/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpereira <fpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:56:33 by fpereira          #+#    #+#             */
/*   Updated: 2023/01/25 11:03:42 by fpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <time.h>
# include <get_next_line.h>
# include <mlx.h>
# include <ft_printf.h>
# define TRUE 1
# define FALSE 0
# define ERROR 0
# define END 0

# define S_WALL 		"sprites/wall.xpm"
# define S_FLOOR 		"sprites/floor.xpm"
# define S_GEM_0 		"sprites/gem_0.xpm"
# define S_GEM_1 		"sprites/gem_1.xpm"
# define S_GEM_2 		"sprites/gem_2.xpm"
# define S_GEM_3 		"sprites/gem_3.xpm"
# define S_GEM_4 		"sprites/gem_4.xpm"
# define S_GEM_5 		"sprites/gem_5.xpm"
# define S_EXIT_OPEN 	"sprites/exit_open.xpm"
# define S_EXIT_CLOSE 	"sprites/exit_closed.xpm"
# define S_PLAYER_R 	"sprites/thanos_r.xpm"
# define S_PLAYER_L		"sprites/thanos_l.xpm"
# define S_PLAYER_U 	"sprites/thanos_u.xpm"
# define S_PLAYER_D		"sprites/thanos_d.xpm"
# define S_ENEMY 		"sprites/enemy.xpm"

# define KEY_W			119
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100
# define KEY_ESC		65307

# define WHITE			"\e[1;37m"
# define GREEN			"\e[1;32m"
# define RESET			"\e[0m"

/* Structs */

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_elements
{
	int				c;
	int				e;
	int				p;
}				t_elements;

typedef struct s_wind
{
	int			x;
	int			y;
}				t_wind;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		size;
}				t_image;

/*typedef enum	imgtype
{
	floor,
	wall,
	exit_close,
};*/

/*while (img[i])
{
	destroyimg img[i].img
	i++
}
img[floor].img*/

typedef struct s_sprite
{
	t_image		floor;
	t_image		wall;
	t_image		exit_close;
	t_image		exit_open;
	t_image		gem0;
	t_image		gem1;
	t_image		gem2;
	t_image		gem3;
	t_image		gem4;
	t_image		gem5;
	t_image		player_l;
	t_image		player_r;
	t_image		player_u;
	t_image		player_d;
	t_image		enemy;
}				t_sprite;

typedef struct s_widlen
{
	int	c_x;
	int	c_y;
	int	x;
	int	y;
}				t_widlen;

typedef struct s_map
{
	t_sprite		sprites;
	char			**map;
	int				steps;
}				t_map;

/* - - - - - - - - */
/*				   */
/* == Functions == */
/*				   */
/* - - - - - - - - */

/* Exits */
void		error(char *error);
void		clear(t_sprite sprites);
int			leave(t_map *map);
int			extra_leave(char *error);
void		sprite_destroyer(t_sprite sprites);

/* Map */
t_list		**map(void);
char		***amap(void);
void		matrix_map(void);
void		map_reader(int fd);
void		map_checker(void);
int			map_len(void);
int			check_top_bot(void);
int			check_border(void);
void		check_elements(void);
int			check_map_build(void);
void		errors_elements(t_elements elem);
int			**checked_alloc(t_widlen widlen);
int			safety(int x, int y, t_widlen widlen);
int			check_path_c(int **checked2, t_widlen widlen,
				int **checked_c, int dir);
int			precheck_path_e(int x, int y, t_widlen widlen);
int			check_path_e(int x, int y, int **checked, t_widlen widlen);
t_widlen	widlen_fill(t_widlen widlen);
int			path_playable(int x, int y, t_widlen widlen, int **checked);
int			map_playable_checker(void);
int			argcheck(int argc, char **argv);
int			map_ccounter(void);
int			possible_collectibles(int x, int y, t_widlen widlen);
t_widlen	wm(int x, int y, t_widlen widlen);
int			**checked_reset(int **checked, t_widlen widlen);
void		checked_free(int **checked, t_widlen widlen);

/* Window */
void		**program(void);
void		**window(void);
t_wind		wsize(char **map);
void		window_start(void);

/* Libft */
void		*ft_calloc(size_t count, size_t size);
void		ft_bzero(void *s, size_t n);
void		*ft_lstadd_back(t_list **lst, t_list *new);
t_list		*ft_lstnew(void *content);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstclear(t_list **lst);
char		*ft_itoa(int n);
int			ft_lstsize(t_list *lst);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strrchr(const char *str, int c);

/* Player */
int			start_player_coord(void);
int			*player_coord(char c);
int			player_rotate(int keycode);
t_map		*open_exits(t_map *map, int key);
int			get_items(t_map *map);
int			refresh_position(int new_y, int new_x, t_map *map, int key);
int			move(int y, int x, t_map *map, int key);
void		make_moves(int keycode, t_map *map);
int			key(int keycode, t_map *map);
int			mouse(int keycode);

/* Sprites & Prints */
t_image		image_mkr(char *path);
t_sprite	spriter(void);
void		printer(t_sprite sprites, int keycode, t_map *map);
void		print_player(t_sprite sprites, int choice);
void		print_elements(t_sprite sprites);
void		print_walls(t_sprite sprites);
t_widlen	collectible_flipper(t_widlen xyc, t_sprite sprites);

/* Enemies */
int			*enemy_coord(char choice);
void		start_enemy_coord(t_map *map);
void		enemy_wait(t_map map, int y, int x);
void		enemy_move(t_map map);
int			enter_the_gotg(t_map *map);
/*void		enemy_rotate(t_sprite sprites, int rotation);*/
void		enemy_movement(t_sprite sprites);
int			enemy_make_move(t_map map, int new_x, int new_y);
int			are_the_guardians_lost(t_map map);
void		move_commit(t_map map, int new_x, int new_y, t_widlen w);

#endif