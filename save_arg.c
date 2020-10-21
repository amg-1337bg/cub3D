/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <bamghoug@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 11:56:20 by bamghoug          #+#    #+#             */
/*   Updated: 2020/05/08 15:22:52 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	create_head(t_resol s_resol, int fd, int *pad)
{
	unsigned int	filesize;
	unsigned char	header[54];

	*pad = (4 - (s_resol.x * 3) % 4) % 4;
	filesize = 54 + (*pad + (s_resol.x * 3)) * s_resol.y;
	ft_memset(header, (unsigned char)0, 54);
	header[0] = 'B';
	header[1] = 'M';
	header[2] = (unsigned char)filesize;
	header[3] = (unsigned char)(filesize >> 8);
	header[4] = (unsigned char)(filesize >> 16);
	header[5] = (unsigned char)(filesize >> 24);
	header[10] = (unsigned char)54;
	header[14] = (unsigned char)40;
	header[18] = (unsigned char)(s_resol.x);
	header[19] = (unsigned char)(s_resol.x >> 8);
	header[20] = (unsigned char)(s_resol.x >> 16);
	header[21] = (unsigned char)(s_resol.x >> 24);
	header[22] = (unsigned char)(s_resol.y);
	header[23] = (unsigned char)(s_resol.y >> 8);
	header[24] = (unsigned char)(s_resol.y >> 16);
	header[25] = (unsigned char)(s_resol.y >> 24);
	header[26] = (unsigned char)1;
	header[28] = (unsigned char)24;
	write(fd, header, 54);
}

void	render_for_saving(t_resol *s_resol)
{
	float	angle;
	int		x1;
	float	fov;

	fov = 60 * (M_PI / 180);
	angle = g_t_play.pov - (fov / 2);
	x1 = 0;
	g_data.img = mlx_new_image(g_init_ptr, s_resol->x, s_resol->y);
	g_data.img_add = mlx_get_data_addr(g_data.img, &g_data.bpp
	, &g_data.ll, &g_data.endian);
	update_dist(angle);
	while (x1 < s_resol->x)
	{
		calculations(s_resol, angle, fov);
		draw(s_resol, x1, g_walls.y_begin, 0);
		angle += fov / s_resol->x;
		x1++;
	}
	sprites(s_resol);
	g_counter = 0;
}

void	allocation(void)
{
	if ((g_sp = (t_sp*)malloc((g_num_sp) * sizeof(t_sp))) == NULL
	|| (g_raydist = (float*)malloc(g_resol.x * sizeof(float))) == NULL)
		error(7);
}

void	bmp_image(t_resol s_resol, t_texs *s_text)
{
	int				fd;
	int				x;
	int				pad;
	unsigned char	bmppad[3];

	x = -1;
	while (++x < 3)
		bmppad[x] = (unsigned char)0;
	fd = open("screen.bmp", O_WRONLY | O_CREAT, S_IRWXU, S_IRWXG);
	allocation();
	create_head(s_resol, fd, &pad);
	handle_textures(s_text);
	find_player_pos(&s_resol);
	initial_sp(&s_resol);
	render_for_saving(&s_resol);
	while (--s_resol.y >= 0)
	{
		x = -1;
		while (++x < s_resol.x)
			write(fd, &((int *)g_data.img_add)[s_resol.y * s_resol.x + x], 3);
		write(fd, bmppad, pad);
	}
	close(fd);
	exit(0);
}
