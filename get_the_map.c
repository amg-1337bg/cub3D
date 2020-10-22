/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_the_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 09:23:07 by bamghoug          #+#    #+#             */
/*   Updated: 2020/10/22 11:57:57 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	search_map(t_resol *s_resol, char *line)
{
	int i;

	i = -1;
	while (line[++i] != '\0')
	{
		if (line[i] != 32 && line[i] != 9)
		{
			if (line[i] == 'R' && line[i + 1] == ' ')
				break ;
			else if ((line[i] == 'N' && line[i + 1] == 'O') ||
					(line[i] == 'S' && line[i + 1] == 'O') ||
					(line[i] == 'W' && line[i + 1] == 'E') ||
					(line[i] == 'E' && line[i + 1] == 'A') || (line[i] == 'S'))
				break ;
			else if ((line[i] == 'F' || line[i] == 'C') && line[i + 1] == ' ')
				break ;
			else if (line[i] == '1' || line[i] == '0')
				get_map(s_resol, line);
			else
				error(7);
			return ;
		}
	}
}
