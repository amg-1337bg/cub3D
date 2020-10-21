/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intial1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <bamghoug@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 17:19:48 by bamghoug          #+#    #+#             */
/*   Updated: 2020/05/07 15:07:42 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	initial_colors(t_colors *colors)
{
	colors->c_blue = -1;
	colors->c_green = -1;
	colors->c_red = -1;
	colors->c_rgb = -1;
	colors->f_blue = -1;
	colors->f_green = -1;
	colors->f_red = -1;
	colors->f_rgb = -1;
}

void	initial_text(t_texs *text)
{
	text->no_tex = NULL;
	text->ea_tex = NULL;
	text->so_tex = NULL;
	text->sp_tex = NULL;
	text->we_tex = NULL;
}

void	initial_sp(t_resol *s_resol)
{
	int i;

	i = -1;
	while (++i < g_num_sp)
	{
		g_sp[i].x = ((g_sp[i].x_map * s_resol->x_tile) - (s_resol->x_tile / 2));
		g_sp[i].y = ((g_sp[i].y_map * s_resol->y_tile) - (s_resol->y_tile / 2));
		g_sp[i].dist = sqrt(pow((g_sp[i].x - g_t_play.x), 2) +
		pow((g_sp[i].y - g_t_play.y), 2));
	}
	sort();
}
