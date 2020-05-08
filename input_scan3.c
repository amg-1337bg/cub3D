/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_scan3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <bamghoug@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 17:01:18 by bamghoug          #+#    #+#             */
/*   Updated: 2020/05/07 14:59:57 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	get_map(t_resol *s_resol, t_texs *textus, t_colors *colors, char *line)
{
	if (g_on == 0)
		check_others(s_resol, textus, colors, &g_on);
	if (g_empty_line == 1 && g_on == 1)
		error(1);
	first_last(line);
	s_resol->dimens[g_dim_ind++] = line_filter(line);
	if (s_resol->x_map == -1)
		s_resol->x_map = ft_strlen(s_resol->dimens[g_dim_ind - 1]);
	else
	{
		if (s_resol->x_map < (int)ft_strlen(s_resol->dimens[g_dim_ind - 1]))
			s_resol->x_map = ft_strlen(s_resol->dimens[g_dim_ind - 1]);
	}
	s_resol->y_map = g_dim_ind;
}

void	first_last(char *line)
{
	int i;
	int last;

	i = -1;
	while (line[++i] != '\0')
	{
		if (line[i] != 32)
		{
			if (line[i] != '1')
				error(1);
			break ;
		}
	}
	last = ft_strlen(line);
	while (line[--last] != '\0')
	{
		if (line[last] != 32)
		{
			if (line[last] != '1')
				error(1);
			break ;
		}
	}
}

char	*line_filter(char *line)
{
	char	*res;
	int		i;

	i = 0;
	if (g_first_map == 0)
		check_first_map(line);
	while (line[i] != '\0')
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == 'N'
				|| line[i] == 'S' || line[i] == 'W'
				|| line[i] == 'E' || line[i] == '2'
				|| line[i] == ' ')
		{
			if (line[i] == '2')
				g_num_sp++;
			i++;
		}
		else
			error(1);
	}
	res = ft_strdup(line);
	return (res);
}
