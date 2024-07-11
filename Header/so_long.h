/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rib <joao-rib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:30:33 by joao-rib          #+#    #+#             */
/*   Updated: 2024/07/11 17:55:14 by joao-rib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <time.h>
//ft_printf
# define CONVERSION "cspdiuxX%"
# define FLAGS "-0# +"
# define DECIMAL "0123456789"
# define HEXA_LOW "0123456789abcdef"
# define HEXA_UPP "0123456789ABCDEF"
//get_next_line
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 40
# endif
# define MAXFD 2000
//so_long
# include "../mlx/minilibx-linux/mlx.h"

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

typedef struct s_map
{
	char			**layout;
	int				num_coins;
	struct s_point	map_size;
	struct s_point	pos_exit;
	struct s_point	pos_player;
}			t_map;

typedef struct s_sprite
{
	int		width;
	int		height;
	void	*img;
}			t_sprite;

typedef struct s_graph
{
	void	*mlx;
	void	*win;
}			t_graph;

typedef struct s_game
{
	struct s_map	*map;
	struct s_sprite	*sprite;
	struct s_graph	display;
	struct s_point	curr;
	struct s_point	next;
	int				moves;
	int				coins;
	int				nsprites;
	int				textpos_y;
}			t_game;

//Utils - Error Handling
int		error_msg(char *msg);
void	error_exit(char *msg, t_game *g);
void	error_map(char *msg, t_game *g);
//Utils - Loading
void	load_map(t_game *g, char *file);
void	load_graphics(t_game *g);
void	load_sprites(t_game *g, int nsprites);
//Utils - Rendering
void	render_map(t_game *g);
int		render_movement(t_game *g);
//Utils - Moving
int		move_handler(int keypress, t_game *g);
void	move_player(t_game *g);
//Utils - Destroying
void	destroy_map(t_game *g);
int		destroy_game(t_game *game);
//Utils - Other
void	validate_map(t_game *g);

//libft
size_t	ft_strlen(const char *str);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strchr(const char *str, int c);
char	*get_next_line(int fd);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_strbuild(char *s1, const char *s2);
char	*ft_strtrim(const char *s1, const char *set);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memset(void *s, int c, size_t n);
char	**ft_strarrdup(char **src);
char	*ft_strdup(const char *src);
int		ft_strchr_pos(const char *str, char c);
char	*ft_itoa(int n);
char	*ft_strjoin(const char *s1, const char *s2);
void	flood_fill_sl(char **tab, t_game *g, t_point begin);

//ft_printf
int		ft_printf(const char *string, ...);
int		ft_putnbr_ubase_fd(unsigned int nbr, char *base, int fd);
int		ft_putnbr_lbase_fd(unsigned long nbr, char *base, int fd);
int		ft_putchar_fd(char c, int fd);
int		ft_putnbr_fd(long n, int fd);
int		ft_putstr_fd(char *str, int fd);

#endif