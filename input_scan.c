/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_scan.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <bamghoug@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 16:54:10 by bamghoug          #+#    #+#             */
/*   Updated: 2020/05/07 14:48:34 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	get_resol(t_resol *res, char *line)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strdup(line);
	tmp = ft_strtrim(tmp, "	 ");
	while (tmp[i] != ' ' && tmp[i] != '\0')
		i++;
	res->x = get_resol_val(&tmp[i]);
	while (tmp[i] == ' ' && tmp[i] != '\0')
		i++;
	while (ft_isdigit(tmp[i]) == 1 && tmp[i] != '\0')
		i++;
	res->y = get_resol_val(&tmp[i]);
	if (res->x > 1440)
		res->x = 1440;
	if (res->y > 1020)
		res->y = 1020;
	free(tmp);
}

int		get_resol_val(char *line)
{
	int res;

	res = ft_atoi(line);
	if (res < 0 || (res == 0 && line[0] != '0'))
		error(2);
	return (res);
}
