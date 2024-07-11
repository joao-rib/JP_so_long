/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rib <joao-rib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:30:33 by joao-rib          #+#    #+#             */
/*   Updated: 2024/07/10 16:27:56 by joao-rib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/so_long.h"

void	error_map(char *msg, t_game *g)
{
	ft_printf("Error: %s\n", msg);
	if (g->map)
		destroy_map(g);
	exit(1);
}

void	error_exit(char *msg, t_game *g)
{
	ft_printf("Error: %s\n", msg);
	destroy_game(g);
	exit(1);
}

int	error_msg(char *msg)
{
	ft_printf("Error: %s\n", msg);
	return (1);
}
