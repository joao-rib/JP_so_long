/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rib <joao-rib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:30:33 by joao-rib          #+#    #+#             */
/*   Updated: 2024/07/11 18:24:32 by joao-rib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/so_long.h"

static void	erase_number(t_game *g)
{
	if (mlx_put_image_to_window(g->display.mlx, g->display.win,
			g->sprite[8].img, 32 * 2, g->textpos_y - 18))
		error_exit("Error during textbox rendering", g);
}

static int	same_pos(t_point pos1, t_point pos2)
{
	if (pos1.x != pos2.x || pos1.y != pos2.y)
		return (0);
	return (1);
}

int	render_movement(t_game *g)
{
	char	*gm;

	if (same_pos(g->next, g->curr)
		|| g->map->layout[g->next.y][g->next.x] == '1')
		return (0);
	else if (g->map->layout[g->next.y][g->next.x] == 'E'
			&& g->coins != g->map->num_coins)
		return (0);
	else if (g->map->layout[g->next.y][g->next.x] == 'B')
		destroy_game(g);
	else if (g->map->layout[g->next.y][g->next.x] == 'H'
			&& g->coins == g->map->num_coins)
		destroy_game(g);
	g->moves++;
	erase_number(g);
	gm = ft_itoa(g->moves);
	if (mlx_string_put(g->display.mlx, g->display.win,
			80, g->textpos_y, 0xFFFFFF, gm))
		error_exit("Error during text rendering", g);
	free(gm);
	move_player(g);
	if (g->map->layout[g->next.y][g->next.x] == 'C')
		g->coins++;
	return (0);
}

static void	render_textbox(t_game *g, int textpos_y, int textpos_x)
{
	int	i;
	int	tx;
	int	ty;

	i = 1;
	tx = textpos_x * g->sprite[9].width;
	ty = textpos_y * g->sprite[7].height;
	if (!mlx_put_image_to_window(g->display.mlx, g->display.win,
			g->sprite[7].img, 0, ty))
		error_exit("Error during textbox rendering", g);
	if (!mlx_put_image_to_window(g->display.mlx, g->display.win,
			g->sprite[9].img, tx, ty))
		error_exit("Error during textbox rendering", g);
	while (i < textpos_x)
	{
		tx = i * g->sprite[8].width;
		if (!mlx_put_image_to_window(g->display.mlx, g->display.win,
				g->sprite[8].img, tx, ty))
			error_exit("Error during textbox rendering", g);
		i++;
	}
}

void	render_map(t_game *g)
{
	t_point	l_pos;
	t_point	s_pos;
	int		i;

	l_pos.y = 0;
	while (g->map->layout[l_pos.y])
	{
		l_pos.x = 0;
		while (g->map->layout[l_pos.y][l_pos.x])
		{
			i = ft_strchr_pos("01CEPHB", g->map->layout[l_pos.y][l_pos.x]);
			s_pos.x = l_pos.x * g->sprite[i].width;
			s_pos.y = l_pos.y * g->sprite[i].height;
			if (!mlx_put_image_to_window(g->display.mlx, g->display.win,
					g->sprite[i].img, s_pos.x, s_pos.y))
				error_exit("Error during sprite rendering", g);
			l_pos.x++;
		}
		l_pos.y++;
	}
	render_textbox(g, l_pos.y, (l_pos.x - 1));
	g->textpos_y = s_pos.y + 50;
	if (mlx_string_put(g->display.mlx, g->display.win, 16,
			g->textpos_y, 0xFFFFFF, "Moves:"))
		error_exit("Error during text rendering", g);
}
