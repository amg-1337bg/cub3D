/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <bamghoug@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 13:10:18 by bamghoug          #+#    #+#             */
/*   Updated: 2020/05/08 15:19:10 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		main(int argc, char **argv)
{
	t_texs	s_textus;

	initial_interc(&g_colors, &s_textus);
	if (argc == 2 || argc == 3)
	{
		if (argc == 2)
			check_args(argv[1], NULL, 1);
		else if (argc == 3)
			check_args(argv[1], argv[2], 2);
		get_configs(&g_resol, &s_textus, &g_colors, argv[1]);
		g_init_ptr = mlx_init();
		g_win_ptr = mlx_new_window(g_init_ptr, g_resol.x, g_resol.y, "cub3d");
		if (argc == 3)
			bmp_image(g_resol, &s_textus);
		ft_render(&g_resol, &s_textus);
	}
	error(5);
	return (0);
}

void	draw(t_resol *s_resol, int x1, float y_begin, int y1)
{
	int		offsetx;
	int		offsety;
	float	begin;
	float	wall_height;

	begin = y_begin;
	wall_height = g_walls.wallheight;
	if (g_walls.y_begin < 0)
		g_walls.y_begin = 0;
	while (++y1 < g_walls.y_begin)
		mpp(&g_data, x1, y1, g_colors.c_rgb);
	if (g_inte.vert_horz == 0)
		offsetx = (int)remainder(g_inte.v_yint, s_resol->y_tile);
	else
		offsetx = (int)remainder(g_inte.h_xint, s_resol->y_tile);
	while (g_walls.wallheight >= 0 && g_walls.y_begin < s_resol->y)
	{
		offsety = (g_walls.y_begin - begin) * ((float)g_ntext.h / wall_height);
		offsety += ((offsetx < 0) ? 1 : 0);
		mpp(&g_data, x1, g_walls.y_begin, get_color(offsetx, offsety));
		g_walls.y_begin++;
		g_walls.wallheight--;
	}
	while (g_walls.y_begin < s_resol->y)
		mpp(&g_data, x1, g_walls.y_begin++, g_colors.f_rgb);
}

void	handle_player(t_resol *s_resol)
{
	float	angle;
	int		x1;
	float	fov;
	int		y1;

	fov = 60 * (M_PI / 180);
	angle = g_t_play.pov - (fov / 2);
	x1 = -1;
	update_dist(angle);
	while (++x1 < s_resol->x)
	{
		y1 = -1;
		calculations(s_resol, angle, fov);
		draw(s_resol, x1, g_walls.y_begin, y1);
		angle += fov / s_resol->x;
	}
	sprites(s_resol);
	mlx_put_image_to_window(g_init_ptr, g_win_ptr, g_data.img, 0, 0);
	g_counter = 0;
}

void	ft_render(t_resol *s_resol, t_texs *s_text)
{
	if ((g_sp = (t_sp*)malloc((g_num_sp) * sizeof(t_sp))) == NULL
	|| (g_raydist = (float*)malloc(s_resol->x * sizeof(float))) == NULL)
		error(7);
	handle_textures(s_text);
	find_player_pos(s_resol);
	initial_sp(s_resol);
	g_data.img = mlx_new_image(g_init_ptr, s_resol->x, s_resol->y);
	g_data.img_add = mlx_get_data_addr(g_data.img, &g_data.bpp,
	&g_data.ll, &g_data.endian);
	handle_player(s_resol);
	g_t_play.rot_speed = 2.5 * M_PI / 180;
	g_t_play.move_speed = 10;
	mlx_hook(g_win_ptr, 2, 1L << 0, deal_key, s_resol);
	mlx_hook(g_win_ptr, 3, 1L << 1, stop, s_resol);
	mlx_hook(g_win_ptr, 17, 1L << 2, red_cross, (void*)0);
	mlx_loop(g_init_ptr);
	return ;
}
