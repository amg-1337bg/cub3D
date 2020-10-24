/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <bamghoug@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 17:12:13 by bamghoug          #+#    #+#             */
/*   Updated: 2020/05/08 14:57:07 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		check_next_pos(float x, float y, t_resol *s_resol)
{
	int mapx;
	int mapy;
	int tmp;

	//printf ("x = %f and y = %f\n", x, y);
	mapx = (int)(x / s_resol->x_tile);
	mapy = (int)(y / s_resol->y_tile);
	if (mapx > (tmp = ft_strlen(s_resol->dimens[mapy])))
		mapx = tmp;
	if (s_resol->dimens[mapy][mapx] == '0' ||
		s_resol->dimens[mapy][mapx] == 'N' ||
		s_resol->dimens[mapy][mapx] == 'S' ||
		s_resol->dimens[mapy][mapx] == 'W' ||
		s_resol->dimens[mapy][mapx] == 'E')
		return (0);
	else if (s_resol->dimens[mapy][mapx] == '2')
		return (2);
	return (1);
}

void	sp_index(int x, int y)
{
	g_sp[g_sp_index].x_map = x + 1;
	g_sp[g_sp_index].y_map = y + 1;
	g_sp_index++;
}

void	find_player_pos(t_resol *s_resol)
{
	int i;
	int j;

	i = -1;
	while (s_resol->dimens[++i] != NULL)
	{
		j = -1;
		while (s_resol->dimens[i][++j] != '\0')
		{
			if (s_resol->dimens[i][j] == 'N' || s_resol->dimens[i][j] == 'S' ||
			s_resol->dimens[i][j] == 'W' || s_resol->dimens[i][j] == 'E')
			{
				initial_pov(s_resol->dimens[i][j]);
				g_t_play.x = (s_resol->x_tile * (j + 1)) -
				(s_resol->x_tile / 2);
				g_t_play.y = (s_resol->y_tile * (i + 1)) -
				(s_resol->y_tile / 2);
			}
			else if (s_resol->dimens[i][j] == '2')
				sp_index(j, i);
		}
	}
	if (g_t_play.pov < 0)
		error(1);
}

void	mpp(t_data *s_data, int x, int y, int color)
{
	char *point;

	point = s_data->img_add + ((int)y * s_data->ll + (int)x *
	(s_data->bpp / 8));
	*(unsigned int*)point = color;
}
