/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_interc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <bamghoug@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 14:28:54 by bamghoug          #+#    #+#             */
/*   Updated: 2020/04/26 15:06:46 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	calculations(t_resol *s_resol, float angle, float fov)
{
	normalize_angle(&angle);
	g_t_play.pov_hit = cast(s_resol, angle);
	g_raydist[g_counter++] = g_t_play.pov_hit;
	g_walls.dpp = (s_resol->x / 2) / tan(fov / 2);
	g_walls.wallheight = (s_resol->x_tile / g_t_play.pov_hit) * g_walls.dpp;
	g_walls.y_begin = (s_resol->y / 2) - (g_walls.wallheight / 2);
}

float	cast(t_resol *s_resol, float angle)
{
	g_inte.vert_horz = 0;
	angle_facing(angle, &g_inte.l_r, &g_inte.up_down);
	horz_inter(s_resol, angle);
	vert_inter(s_resol, angle);
	if (g_inte.h_dist < g_inte.v_dist)
	{
		g_inte.vert_horz = 1;
		return (g_inte.h_dist);
	}
	return (g_inte.v_dist);
}

void	vert_inter(t_resol *s_resol, float angle)
{
	g_inte.v_xint = floor(g_t_play.x / s_resol->x_tile) * s_resol->x_tile;
	g_inte.v_xint += (g_inte.l_r == 1) ? s_resol->x_tile : 0;
	g_inte.v_xstep = s_resol->x_tile;
	g_inte.v_xstep *= (g_inte.l_r == 0) ? -1 : 1;
	g_inte.v_yint = g_t_play.y + (g_inte.v_xint - g_t_play.x) * tan(angle);
	g_inte.v_ystep = s_resol->y_tile * tan(angle);
	g_inte.v_ystep *= (g_inte.up_down == 1 && g_inte.v_ystep > 0) ? -1 : 1;
	g_inte.v_ystep *= (g_inte.up_down == 0 && g_inte.v_ystep < 0) ? -1 : 1;
	while (g_inte.v_xint >= 0 && g_inte.v_yint >= 0 &&
g_inte.v_xint <= (s_resol->x_map * s_resol->x_tile) &&
g_inte.v_yint <= (s_resol->y_map * s_resol->y_tile))
	{
		if (check_next_pos(floor(g_inte.v_xint - ((g_inte.l_r == 0) ? 1 : 0)),
g_inte.v_yint, s_resol) == 1)
			break ;
		g_inte.v_xint += g_inte.v_xstep;
		g_inte.v_yint += g_inte.v_ystep;
	}
	g_inte.v_dist = sqrt(pow((g_inte.v_xint - g_t_play.x), 2) +
pow((g_inte.v_yint - g_t_play.y), 2));
	g_inte.v_dist *= cos(g_t_play.pov - angle);
}

void	horz_inter(t_resol *s_resol, float angle)
{
	g_inte.h_yint = floor(g_t_play.y / s_resol->y_tile) * s_resol->y_tile;
	g_inte.h_ystep = s_resol->y_tile;
	if (g_inte.up_down == 0)
		g_inte.h_yint += s_resol->y_tile;
	else if (g_inte.up_down == 1)
		g_inte.h_ystep *= -1;
	g_inte.h_xint = g_t_play.x + (g_inte.h_yint - g_t_play.y) / tan(angle);
	g_inte.h_xstep = s_resol->x_tile / tan(angle);
	if (g_inte.l_r == 0 && g_inte.h_xstep > 0)
		g_inte.h_xstep *= -1;
	else if (g_inte.l_r == 1 && g_inte.h_xstep < 0)
		g_inte.h_xstep *= -1;
	while (g_inte.h_xint >= 0 && g_inte.h_yint >= 0 &&
g_inte.h_xint <= (s_resol->x_map * s_resol->x_tile) &&
g_inte.h_yint <= (s_resol->y_map * s_resol->y_tile))
	{
		if (check_next_pos(g_inte.h_xint, g_inte.h_yint -
((g_inte.up_down == 1) ? 1 : 0), s_resol) == 1)
			break ;
		g_inte.h_xint += g_inte.h_xstep;
		g_inte.h_yint += g_inte.h_ystep;
	}
	g_inte.h_dist = sqrt(pow((g_inte.h_xint - g_t_play.x), 2) +
pow((g_inte.h_yint - g_t_play.y), 2));
	g_inte.h_dist *= cos(g_t_play.pov - angle);
}
