/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <bamghoug@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 22:12:48 by bamghoug          #+#    #+#             */
/*   Updated: 2020/10/17 16:23:58 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	change_val(int key, float *a)
{
	*a = 0;
	if (key == 123)
		g_t_play.dir = -1;
	else if (key == 124)
		g_t_play.dir = 1;
	else if (key == 1)
		g_t_play.speed = -1;
	else if (key == 13)
		g_t_play.speed = 1;
	else if (key == 0)
	{
		*a = -90 * (M_PI / 180);
		g_t_play.speed = 1;
	}
	else if (key == 2)
	{
		*a = 90 * (M_PI / 180);
		g_t_play.speed = 1;
	}
	else if (key == 53)
	{
		mlx_clear_window(g_init_ptr, g_win_ptr);
		mlx_destroy_window(g_init_ptr, g_win_ptr);
		exit(0);
	}
}

int		stop(int key)
{
	if (key == 123 || key == 124)
		g_t_play.dir = 0;
	else if (key == 13 || key == 1 || key == 2 || key == 0)
		g_t_play.speed = 0;
	return (0);
}

int		deal_key(int key, t_resol *s_resol)
{
	float movestep;
	float newposx;
	float newposy;
	float a_d;
	float new_angle;

	mlx_destroy_image(g_init_ptr, g_data.img);
	g_data.img = mlx_new_image(g_init_ptr, s_resol->x, s_resol->y);
	g_data.img_add = mlx_get_data_addr(g_data.img, &g_data.bpp,
&g_data.ll, &g_data.endian);
	change_val(key, &a_d);
	movestep = g_t_play.speed * g_t_play.move_speed;
	g_t_play.pov += g_t_play.dir * g_t_play.rot_speed;
	new_angle = g_t_play.pov + a_d;
	normalize_angle(&new_angle);
	normalize_angle(&g_t_play.pov);
	newposx = g_t_play.x + cos(new_angle) * movestep;
	newposy = g_t_play.y + sin(new_angle) * movestep;
	if (check_next_pos(newposx, newposy, s_resol) == 0)
	{
		g_t_play.x = newposx;
		g_t_play.y = newposy;
	}
	handle_player(s_resol);
	return (1);
}

int		red_cross(int key)
{
	if (key == 0)
		exit(0);
	return (0);
}
