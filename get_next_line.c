/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 21:13:16 by bamghoug          #+#    #+#             */
/*   Updated: 2020/02/05 11:27:07 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		check(char *string)
{
	int i;

	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*before_n(char *s)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] != '\n')
		i++;
	res = (char*)malloc(i + 1);
	while (j < i)
	{
		res[j] = s[j];
		j++;
	}
	res[j] = '\0';
	return (res);
}

int		rest_check(char *rest, char **line)
{
	char *tmp;

	if (check(rest) == 1)
	{
		tmp = *line;
		*line = before_n(rest);
		free(tmp);
		return (1);
	}
	else
	{
		tmp = *line;
		*line = ft_strdup(rest);
		if (tmp)
		{
			free(tmp);
			tmp = NULL;
		}
	}
	return (0);
}

int		work_todo(int fd, char *buf, char **line)
{
	char	*tmp;
	char	*tmp1;
	int		i;

	while ((i = read(fd, buf, BUFFER_SIZE)))
	{
		buf[i] = '\0';
		if (check(buf) == 0)
		{
			tmp = *line;
			*line = ft_strjoin(*line, buf);
			free(tmp);
		}
		else
		{
			tmp = *line;
			tmp1 = before_n(buf);
			*line = ft_strjoin(*line, tmp1);
			free(tmp);
			free(tmp1);
			return (1);
		}
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*rest;
	char		*buf;
	char		*tmp;

	if (fd < 0 || !line || read(fd, NULL, 0))
		return (-1);
	*line = ft_strdup("");
	if (rest && ((rest_check(rest, &(*line))) == 1))
	{
		rest = after_n(rest);
		return (1);
	}
	if ((buf = (char*)malloc(BUFFER_SIZE + 1)) == NULL)
		return (-1);
	if ((work_todo(fd, buf, &(*line))) == 1)
	{
		tmp = rest;
		rest = after_n(buf);
		free(tmp);
		return (1);
	}
	free(buf);
	free(rest);
	rest = NULL;
	return (0);
}
