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
	char	*tmp1;
	int		i;

	if (res->x > 0 && res->y > 0)
		error(2);
	i = 0;
	tmp = ft_strdup(line);
	tmp = ft_strtrim(tmp, "	 ");
	while (tmp[i] != ' ' && tmp[i] != '\0')
		i++;
	res->x = get_resol_val(&tmp[i]);
	ignor_sp_dig(tmp, &i);
	res->y = get_resol_val(&tmp[i]);
	res->x = (res->x > 2048) ? 2048 : res->x;
	res->y = (res->y > 1152) ? 1152 : res->y;
	ignor_sp_dig(tmp, &i);
	tmp1 = ft_strdup(&tmp[i]);
	tmp1 = ft_strtrim(tmp1, " 	");
	if (*tmp1 != '\0')
		error(2);
	free(tmp1);
	free(tmp);
}

void	ignor_sp_dig(char *str, int *i)
{
	while (str[*i] == ' ' && str[*i] != '\0')
		(*i)++;
	while (ft_isdigit(str[*i]) == 1 && str[*i] != '\0')
		(*i)++;
}

int		get_resol_val(char *line)
{
	int res;

	res = ft_atoi(line);
	if (res < 0 || (res == 0 && line[0] != '0'))
		error(2);
	return (res);
}
