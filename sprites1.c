/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <bamghoug@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 22:47:20 by bamghoug          #+#    #+#             */
/*   Updated: 2020/04/18 22:51:13 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		sprite_pos(double x, double y, t_resol *s_resol)
{
	int mapx;
	int mapy;

	mapx = (int)(x / s_resol->x_tile);
	mapy = (int)(y / s_resol->y_tile);
	if (s_resol->dimens[mapy][mapx] == '0' || s_resol->dimens[mapy][mapx] == 'N'
			|| s_resol->dimens[mapy][mapx] == 'S' ||
s_resol->dimens[mapy][mapx] == 'W'
			|| s_resol->dimens[mapy][mapx] == 'E')
		return (0);
	if (s_resol->dimens[mapy][mapx] == '2')
		return (2);
	return (1);
}

void	swap(int f, int t)
{
	t_sp tmp;

	tmp.x = g_sp[t].x;
	tmp.y = g_sp[t].y;
	tmp.dist = g_sp[t].dist;
	g_sp[t].x = g_sp[f].x;
	g_sp[t].y = g_sp[f].y;
	g_sp[t].dist = g_sp[f].dist;
	g_sp[f].x = tmp.x;
	g_sp[f].y = tmp.y;
	g_sp[f].dist = tmp.dist;
}
