/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <bamghoug@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 17:02:40 by bamghoug          #+#    #+#             */
/*   Updated: 2020/05/08 21:55:40 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	check_others(t_resol *s_resol, t_texs *textus, t_colors *colors,
int *on)
{
	if (s_resol->x < 0 || s_resol->y < 0 || textus->ea_tex == NULL ||
	textus->no_tex == NULL
		|| textus->so_tex == NULL || textus->sp_tex == NULL ||
		textus->we_tex == NULL
		|| colors->c_blue < 0 || colors->c_green < 0 || colors->c_red < 0
		|| colors->f_blue < 0 || colors->f_green < 0 || colors->f_red < 0)
		error(7);
	*on = 1;
}

void	verify(char *line, int f, int l)
{
	while (f < l)
	{
		if (line[f] != '1')
		{
			if (line[f] != ' ')
				error(1);
		}
		f++;
	}
}

void	looking_for_ones(char *line, int f, int *b, int *a)
{
	int i;

	i = f;
	*b = 1;
	*a = 1;
	f = (f > (int)ft_strlen(line)) ? ft_strlen(line) : f;
	if (line[f] == '0' || line[f] == '2')
		error(1);
	else if (line[f] == ' ')
	{
		while (i >= 0 && line[i] == ' ')
			i--;
		if (i < 0 && line[0] == ' ')
			*b = 1;
		else
			*b = (line[i] == '1') ? 1 : 0;
		while (line[f] == ' ')
			f++;
		*a = (line[f] == '1') ? 1 : 0;
	}
	else if (line[f] == '1')
	{
		*b = 1;
		*a = 1;
	}
}

void	space_looking(t_resol *s_resol, int i, int f, int l)
{
	int before;
	int after;
	int j;
	int k;

	while (f <= l)
	{
		if (s_resol->dimens[i][f] == ' ')
		{
			j = f;
			k = f;
			while (j > 0 && s_resol->dimens[i][j] == ' ')
				j--;
			while (s_resol->dimens[i][k] != '\0' &&
			s_resol->dimens[i][k] == ' ')
				k++;
			if (s_resol->dimens[i][j] != '1' || s_resol->dimens[i][k] != '1')
				error(1);
			looking_for_ones(s_resol->dimens[i + 1], f, &before, &after);
			if (before != 1 || after != 1)
				error(1);
			f++;
		}
		f++;
	}
}

void	space_back_looking(t_resol *s_resol, int i, int f, int l)
{
	int before;
	int after;

	while (f <= l)
	{
		if (s_resol->dimens[i][f] == ' ')
		{
			looking_for_ones(s_resol->dimens[i - 1], f, &before, &after);
			if (before != 1 || after != 1)
				error(1);
			f++;
		}
		else
			f++;
	}
}
