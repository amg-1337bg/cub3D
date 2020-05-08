/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_text.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <bamghoug@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 22:15:00 by bamghoug          #+#    #+#             */
/*   Updated: 2020/04/18 23:47:59 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	sprite_ptr(t_texs *s_text)
{
	if ((g_sptext.xp_img = mlx_xpm_file_to_image(g_init_ptr, s_text->sp_tex
			, &g_sptext.w, &g_sptext.h)) == NULL)
		error(3);
	g_sptext.img_addr = (int *)mlx_get_data_addr(g_sptext.xp_img
			, &g_sptext.bpp, &g_sptext.sl, &g_sptext.end);
}

void	handle_textures(t_texs *s_text)
{
	if ((g_ntext.xp_img = mlx_xpm_file_to_image(g_init_ptr, s_text->no_tex
			, &g_ntext.w, &g_ntext.h)) == NULL)
		error(3);
	g_ntext.img_addr = (int *)mlx_get_data_addr(g_ntext.xp_img
			, &g_ntext.bpp, &g_ntext.sl, &g_ntext.end);
	if ((g_stext.xp_img = mlx_xpm_file_to_image(g_init_ptr, s_text->so_tex
			, &g_stext.w, &g_stext.h)) == NULL)
		error(3);
	g_stext.img_addr = (int *)mlx_get_data_addr(g_stext.xp_img
			, &g_stext.bpp, &g_stext.sl, &g_stext.end);
	if ((g_wtext.xp_img = mlx_xpm_file_to_image(g_init_ptr, s_text->we_tex
			, &g_wtext.w, &g_wtext.h)) == NULL)
		error(3);
	g_wtext.img_addr = (int *)mlx_get_data_addr(g_wtext.xp_img
			, &g_wtext.bpp, &g_wtext.sl, &g_wtext.end);
	if ((g_etext.xp_img = mlx_xpm_file_to_image(g_init_ptr, s_text->ea_tex
			, &g_etext.w, &g_etext.h)) == NULL)
		error(3);
	g_etext.img_addr = (int *)mlx_get_data_addr(g_etext.xp_img
			, &g_etext.bpp, &g_etext.sl, &g_etext.end);
	sprite_ptr(s_text);
}
