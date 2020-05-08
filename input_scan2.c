/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_scan2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <bamghoug@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 16:58:46 by bamghoug          #+#    #+#             */
/*   Updated: 2020/05/07 14:56:18 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	get_colors(t_colors *colors, char *line)
{
	char *tmp;

	tmp = ft_strdup(line);
	tmp = ft_strtrim(tmp, "	 ");
	if (ft_strnstr(tmp, "F", 1) != NULL)
		get_f_colors(colors, tmp);
	else if (ft_strnstr(tmp, "C", 1) != NULL)
		get_c_colors(colors, tmp);
	free(tmp);
}

void	get_f_colors(t_colors *colors, char *line)
{
	int i;

	i = 0;
	while ((line[i] >= 65 && line[i] <= 90) || line[i] == 32
			|| line[i] == 9)
		i++;
	colors->f_red = get_color_val(&line[i], 0);
	while (line[i] != ',' && line[i] != '\0')
		i++;
	colors->f_green = get_color_val(&line[i], 1);
	i++;
	while (line[i] != ',' && line[i] != '\0')
		i++;
	colors->f_blue = get_color_val(&line[i], 1);
	colors->f_rgb = ((colors->f_red * 65536) + (colors->f_green * 256)
			+ colors->f_blue);
}

void	get_c_colors(t_colors *colors, char *line)
{
	int i;

	i = 0;
	while ((line[i] >= 65 && line[i] <= 90) || line[i] == 32
			|| line[i] == 9)
		i++;
	colors->c_red = get_color_val(&line[i], 0);
	while (line[i] != ',' && line[i] != '\0')
		i++;
	colors->c_green = get_color_val(&line[i], 1);
	i++;
	while (line[i] != ',' && line[i] != '\0')
		i++;
	colors->c_blue = get_color_val(&line[i], 1);
	colors->c_rgb = ((colors->c_red * 65536) + (colors->c_green * 256)
			+ colors->c_blue);
}

int		get_color_val(char *line, int i)
{
	int k;
	int res;

	k = 0;
	if (i == 0)
	{
		res = ft_atoi(line);
		if ((res == 0 && line[0] != '0') || (res < 0 && res > 255))
			error(4);
	}
	else
	{
		if (line[k] != ',')
			error(4);
		else
		{
			res = ft_atoi(&line[++k]);
			if ((res == 0 && line[k] != '0') || (res < 0 && res > 255))
				error(4);
		}
	}
	return (res);
}
