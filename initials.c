/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initials.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <bamghoug@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 10:42:53 by bamghoug          #+#    #+#             */
/*   Updated: 2020/05/07 14:20:12 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	error(int i)
{
	if (i == 1)
		write(1, g_errors.map_error, ft_strlen(g_errors.map_error));
	else if (i == 2)
		write(1, g_errors.resol_error, ft_strlen(g_errors.resol_error));
	else if (i == 3)
		write(1, g_errors.text_error, ft_strlen(g_errors.text_error));
	else if (i == 4)
		write(1, g_errors.color_error, ft_strlen(g_errors.color_error));
	else if (i == 5)
		write(1, g_errors.arg_error, ft_strlen(g_errors.arg_error));
	else if (i == 6)
		write(1, g_errors.file_error, ft_strlen(g_errors.file_error));
	else if (i == 7)
		write(1, g_errors.other, ft_strlen(g_errors.other));
	write(1, "\n", 1);
	exit(1);
}

void	initial_errors(void)
{
	g_errors.map_error = "Error\nMAP ERROR. PLEASE FIX IT!!";
	g_errors.resol_error = "Error\nRESOLUTION ERROR. PLEASE FIX IT!!";
	g_errors.text_error = "Error\nTEXTURE ERROR. PLEASE FIX IT!!";
	g_errors.color_error = "Error\nCOLOR ERROR. PLEASE FIX IT!!";
	g_errors.arg_error = "Error\nARGUMENTS ERROR. PLEASE FIX IT!!";
	g_errors.file_error = "Error\nFILE NOT FOUND!!";
	g_errors.other = "Error\nOTHER ERRORS!! PLEASE CHECK THE FILE.";
}

void	initial_configs(void)
{
	g_resol.dimens = NULL;
	g_resol.x = 0;
	g_resol.x_map = -1;
	g_resol.y = 0;
	g_resol.y_map = -1;
	g_resol.x_tile = 32;
	g_resol.y_tile = 32;
	g_t_play.pov = -1;
}

void	initial_pov(char c)
{
	if (g_t_play.pov >= 0)
		error(1);
	if (c == 'N')
		g_t_play.pov = 270 * (M_PI / 180);
	else if (c == 'S')
		g_t_play.pov = 90 * (M_PI / 180);
	else if (c == 'W')
		g_t_play.pov = 180 * (M_PI / 180);
	else if (c == 'E')
		g_t_play.pov = 0 * (M_PI / 180);
}

void	initial_interc(t_colors *colors, t_texs *text)
{
	g_inte.h_xint = 0;
	g_inte.h_yint = 0;
	g_inte.v_xint = 0;
	g_inte.v_yint = 0;
	g_inte.h_xstep = 0;
	g_inte.h_ystep = 0;
	g_inte.v_xstep = 0;
	g_inte.v_ystep = 0;
	g_inte.sp_xinterc = -1;
	g_inte.sp_yinterc = -1;
	g_sptext.sp_x = -1;
	g_sptext.sp_y = -1;
	initial_errors();
	initial_configs();
	initial_colors(colors);
	initial_text(text);
}
