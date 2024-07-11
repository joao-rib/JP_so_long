/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rib <joao-rib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:30:33 by joao-rib          #+#    #+#             */
/*   Updated: 2024/07/11 18:19:22 by joao-rib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/so_long.h"

static void	open_exit(t_game *g)
{
	int	w;
	int	h;

	w = g->sprite[5].width;
	h = g->sprite[5].height;
	g->map->layout[g->map->pos_exit.y][g->map->pos_exit.x] = 'H';
	mlx_put_image_to_window(g->display.mlx, g->display.win,
		g->sprite[5].img, g->map->pos_exit.x * w, g->map->pos_exit.y * h);
	mlx_string_put(g->display.mlx, g->display.win, 112, g->textpos_y, 0xFFFFFF,
		"Happy cow!");
}

void	move_player(t_game *g)
{
	int	i;
	int	w;
	int	h;

	g->map->layout[g->curr.y][g->curr.x] = '0';
	if (g->map->layout[g->next.y][g->next.x] == 'C')
		g->coins++;
	g->map->layout[g->next.y][g->next.x] = 'P';
	i = ft_strchr_pos("01CEPH", g->map->layout[g->curr.y][g->curr.x]);
	w = g->sprite[i].width;
	h = g->sprite[i].height;
	mlx_put_image_to_window(g->display.mlx, g->display.win,
		g->sprite[i].img, g->curr.x * w, g->curr.y * h);
	i = ft_strchr_pos("01CEPH", g->map->layout[g->next.y][g->next.x]);
	mlx_put_image_to_window(g->display.mlx, g->display.win,
		g->sprite[i].img, g->next.x * w, g->next.y * h);
	if (g->coins == g->map->num_coins)
		open_exit(g);
	g->curr = g->next;
}

int	move_handler(int keypress, t_game *g)
{
	if (keypress == 65307)
		destroy_game(g);
	else if (keypress == 'w' || keypress == 'W' || keypress == 65362)
		g->next = (t_point){g->curr.x, g->curr.y - 1};
	else if (keypress == 'a' || keypress == 'A' || keypress == 65361)
		g->next = (t_point){g->curr.x - 1, g->curr.y};
	else if (keypress == 's' || keypress == 'S' || keypress == 65364)
		g->next = (t_point){g->curr.x, g->curr.y + 1};
	else if (keypress == 'd' || keypress == 'D' || keypress == 65363)
		g->next = (t_point){g->curr.x + 1, g->curr.y};
	return (keypress);
}
