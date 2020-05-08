/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <bamghoug@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 21:15:49 by bamghoug          #+#    #+#             */
/*   Updated: 2020/05/07 14:18:15 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*after_n(char *s)
{
	char	*res;
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
		{
			s[i] = '\0';
			res = ft_strdup(&(s[i + 1]));
			free(s);
			return (res);
		}
		i++;
	}
	return (NULL);
}
