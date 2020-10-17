/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <bamghoug@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 17:19:07 by bamghoug          #+#    #+#             */
/*   Updated: 2020/05/06 18:06:17 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	angle_facing(float angle, int *l_r, int *up_down)
{
	*l_r = 0;
	*up_down = 0;
	if (angle >= M_PI && angle <= 2 * M_PI)
		*up_down = 1;
	if (angle >= (1.5 * M_PI) || angle <= M_PI / 2)
		*l_r = 1;
}

int		get_color(int x, int y)
{
	int point;

	if (g_inte.l_r == 0)
	{
		if (g_inte.vert_horz == 0)
			point = (int)g_wtext.img_addr[(g_wtext.w * y) + x];
		else
		{
			point = (int)(g_inte.up_down == 1) ?
			g_ntext.img_addr[(g_ntext.w * y) + x]
				: g_stext.img_addr[(g_stext.w * y) + x];
		}
	}
	else
	{
		if (g_inte.vert_horz == 0)
			point = (int)g_etext.img_addr[(g_etext.w * y) + x];
		else
		{
			point = (int)(g_inte.up_down == 1) ?
			g_ntext.img_addr[(g_ntext.w * y) + x]
				: g_stext.img_addr[(g_stext.w * y) + x];
		}
	}
	return (point);
}

int		sprite_tranc(int x, int y, int sp_size)
{
	int point;

	point = (int)g_sptext.img_addr[g_sptext.w * (y * g_sptext.h / sp_size)
				+ (x * g_sptext.w / sp_size)];
	return (point);
}

void	normalize_angle(float *angle)
{
	*angle = remainder(*angle, (2 * M_PI));
	if (*angle < 0)
		*angle = (2 * M_PI) + *angle;
}
