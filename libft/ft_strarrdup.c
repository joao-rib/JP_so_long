/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rib <joao-rib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:30:33 by joao-rib          #+#    #+#             */
/*   Updated: 2024/07/05 17:50:01 by joao-rib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/so_long.h"

static char	**free_all(char **tab, int w)
{
	while (w >= 0)
	{
		free(tab[w]);
		w--;
	}
	free(tab);
	return (NULL);
}

char	**ft_strarrdup(char **src)
{
	char	**dest;
	int		i;
	int		w;

	w = 0;
	while (src[w] != NULL)
		w++;
	dest = ft_calloc(w + 1, sizeof(char *));
	if (!dest)
		return (NULL);
	dest[w] = NULL;
	w--;
	while (w >= 0)
	{
		i = 0;
		dest[w] = ft_strdup(src[w]);
		if (!dest[w])
			return (free_all(dest, w - 1));
		w--;
	}
	return (dest);
}
