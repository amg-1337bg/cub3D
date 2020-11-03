/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_scan1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <bamghoug@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 16:57:36 by bamghoug          #+#    #+#             */
/*   Updated: 2020/05/07 14:50:40 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	get_textures(t_texs *textus, char *line)
{
	char *tmp;

	tmp = ft_strdup(line);
	tmp = ft_strtrim(tmp, " ");
	if (ft_strnstr(tmp, "NO", 2) != NULL)
		textus->no_tex = get_path(tmp, textus->no_tex);
	else if (ft_strnstr(tmp, "SO", 2) != NULL)
		textus->so_tex = get_path(tmp, textus->so_tex);
	else if (ft_strnstr(tmp, "WE", 2) != NULL)
		textus->we_tex = get_path(tmp, textus->we_tex);
	else if (ft_strnstr(tmp, "EA", 2) != NULL)
		textus->ea_tex = get_path(tmp, textus->ea_tex);
	else if (ft_strnstr(tmp, "S", 1) != NULL)
		textus->sp_tex = get_path(tmp, textus->sp_tex);
	free(tmp);
}

char	*get_path(char *line, char *texture)
{
	int		i;
	char	*res;

	i = 0;
	res = NULL;
	if (texture != NULL)
		error(3);
	while (line[i] != '\0')
	{
		if ((line[i] >= 65 && line[i] <= 90) || line[i] == 32 ||
				line[i] == 9)
			i++;
		else
		{
			res = ft_strdup(&line[i]);
			break ;
		}
	}
	check_extension(res);
	return (res);
}

void	check_extension(char *st)
{
	int		len;
	char	*must;
	int		i;

	len = ft_strlen(st);
	must = ".xpm";
	i = -1;
	len -= 4;
	while (++i < 4 && st[len] != '\0')
	{
		if (must[i] != st[len])
			error(3);
		len++;
	}
}
