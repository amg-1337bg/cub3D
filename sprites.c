/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <bamghoug@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 22:37:12 by bamghoug          #+#    #+#             */
/*   Updated: 2020/05/08 15:23:07 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	get_sp_coor(t_sp *sp, float angle)
{
	sp->dist = sqrt(pow((sp->x - g_t_play.x), 2) +
	pow((sp->y - g_t_play.y), 2));
	sp->dist *= cos(g_t_play.pov - angle);
}

void	sort(void)
{
	int i;
	int j;

	j = 0;
	while (j < g_num_sp)
	{
		i = 0;
		while (i < g_num_sp)
		{
			if (g_sp[i].dist < g_sp[i + 1].dist)
				swap(i, i + 1);
			i++;
		}
		j++;
	}
}

void	update_dist(float angle)
{
	int i;

	i = -1;
	while (++i < g_num_sp)
		get_sp_coor(&g_sp[i], angle);
	sort();
}

void	render_sp(int x, int y, int size, int k)
{
	int col;
	int i;
	int j;

	i = -1;
	while (++i < size)
	{
		if (x + i < 0 || x + i >= g_resol.x)
			continue;
		if (g_sp[k].dist >= g_raydist[x + i])
			continue;
		j = -1;
		while (++j < size)
		{
			col = sprite_tranc(i, j, size);
			if (col != 0)
				if (((x + i) >= 0 && (x + i) < g_resol.x) &&
						((y + j) >= 0 && (y + j) < g_resol.y))
					mpp(&g_data, x + i, y + j, col);
		}
	}
}

void	sprites(t_resol *s_resol)
{
	float	angle;
	float	size;
	float	x;
	float	y;
	int		i;

	i = -1;
	while (++i < g_num_sp)
	{
		angle = atan2(g_sp[i].y - g_t_play.y, g_sp[i].x - g_t_play.x);
		while (angle - g_t_play.pov > M_PI)
			angle -= 2 * M_PI;
		while (angle - g_t_play.pov < -M_PI)
			angle += 2 * M_PI;
		if (s_resol->y > s_resol->x)
			size = (s_resol->y / g_sp[i].dist) * s_resol->y_tile;
		else
			size = (s_resol->x / g_sp[i].dist) * s_resol->x_tile;
		y = s_resol->y / 2 - size / 2;
		x = (angle - g_t_play.pov) *
				s_resol->x / (60 * M_PI / 180) +
			(s_resol->x / 2 - size / 2);
		render_sp(x, y, size, i);
	}
}
