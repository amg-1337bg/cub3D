/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <bamghoug@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 16:45:09 by bamghoug          #+#    #+#             */
/*   Updated: 2020/05/07 14:41:13 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	get_configs(t_resol *s_resol, t_texs *textus,
t_colors *colors, char *file)
{
	char	*line;
	int		fd;
	int		init;

	init = -1;
	if ((s_resol->dimens = (char **)malloc((200) * sizeof(char*))) == NULL)
		error(7);
	while (++init < 200)
		s_resol->dimens[init] = NULL;
	if ((fd = open(file, O_RDONLY)) == -1)
		error(6);
	while (get_next_line(fd, &line))
	{
		search(s_resol, textus, colors, line);
		free(line);
	}
	if (line != NULL)
	{
		search(s_resol, textus, colors, line);
		free(line);
	}
	check_colors(colors);
	check_first_map(s_resol->dimens[--g_dim_ind]);
	check_map(s_resol);
	close(fd);
}

void	search(t_resol *s_resol, t_texs *textus, t_colors *colors, char *line)
{
	int i;

	i = -1;
	while (line[++i] != '\0')
	{
		if (line[i] != 32 && line[i] != 9)
		{
			if (line[i] == 'R' && line[i + 1] == ' ')
				get_resol(s_resol, line);
			else if ((line[i] == 'N' && line[i + 1] == 'O') ||
					(line[i] == 'S' && line[i + 1] == 'O') ||
					(line[i] == 'W' && line[i + 1] == 'E') ||
					(line[i] == 'E' && line[i + 1] == 'A') || (line[i] == 'S'))
				get_textures(textus, line);
			else if ((line[i] == 'F' || line[i] == 'C') && line[i + 1] == ' ')
				get_colors(colors, line);
			else if (line[i] == '1' || line[i] == '0')
				get_map(s_resol, textus, colors, line);
			else
				error(7);
			return ;
		}
	}
	if (g_empty_line == 0 && g_on == 1)
		g_empty_line = 1;
}

void	check_colors(t_colors *colors)
{
	if (colors->c_blue < 0 || colors->c_green < 0 || colors->c_red < 0
		|| colors->f_blue < 0 || colors->f_green < 0 || colors->f_red < 0)
		error(4);
	if (colors->c_blue > 255 || colors->c_green > 255 || colors->c_red > 255
		|| colors->f_blue > 255 || colors->f_green > 255 || colors->f_red > 255)
		error(4);
}

void	check_first_map(char *line)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strdup(line);
	tmp = ft_strtrim(tmp, " ");
	while (tmp[i] == '1' || tmp[i] == ' ')
		i++;
	if (tmp[i] != '\0' && tmp[i] != '1' && tmp[i] != ' ')
		error(1);
	free(tmp);
	g_first_map = 1;
}

void	check_map(t_resol *s_resol)
{
	int i;

	i = -1;
	while (++i < g_dim_ind)
		check_length(s_resol, i);
	i += 1;
	while (--i > 0)
		check_back_length(s_resol, i);
}
