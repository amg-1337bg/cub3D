/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <bamghoug@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 17:04:43 by bamghoug          #+#    #+#             */
/*   Updated: 2020/05/07 13:48:02 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	check_length(t_resol *s_resol, int ind)
{
	int	f1;
	int f2;
	int l1;
	int l2;

	ignor_spaces(s_resol->dimens[ind], &f1, &l1);
	ignor_spaces(s_resol->dimens[ind + 1], &f2, &l2);
	space_looking(s_resol, ind, f1, l1);
	if (f1 < f2)
		verify(s_resol->dimens[ind], f1, f2);
	else if (f1 > f2)
		verify(s_resol->dimens[ind + 1], f2, f1);
	if (l1 < l2)
		verify(s_resol->dimens[ind + 1], l1 + 1, l2 + 1);
	else if (l1 > l2)
		verify(s_resol->dimens[ind], l2 + 1, l1 + 1);
}

void	check_back_length(t_resol *s_resol, int ind)
{
	int	f1;
	int f2;
	int l1;
	int l2;

	ignor_spaces(s_resol->dimens[ind], &f1, &l1);
	ignor_spaces(s_resol->dimens[ind - 1], &f2, &l2);
	space_back_looking(s_resol, ind, f1, l1);
	if (f1 < f2)
		verify(s_resol->dimens[ind], f1, f2);
	else if (f1 > f2)
		verify(s_resol->dimens[ind - 1], f2, f1);
	if (l1 < l2)
		verify(s_resol->dimens[ind - 1], l1 + 1, l2 + 1);
	else if (l1 > l2)
		verify(s_resol->dimens[ind], l2 + 1, l1 + 1);
}

void	ignor_spaces(char *line, int *f, int *l)
{
	int i;

	i = -1;
	while (line[++i] != '\0')
	{
		if (line[i] == '1')
			break ;
	}
	*f = i;
	i = ft_strlen(line);
	while (--i >= 0)
	{
		if (line[i] == '1')
			break ;
	}
	*l = i;
}

void	check_args(char *cub, char *save, int i)
{
	if (i == 1)
		check_file_name(cub);
	else if (i == 2)
	{
		check_file_name(cub);
		if (ft_strnstr(save, "--save", 6) == NULL)
			error(5);
	}
}

void	check_file_name(char *file_name)
{
	int		i;
	int		len;
	char	*must;

	i = 3;
	len = ft_strlen(file_name);
	len--;
	must = ".cub";
	while (i >= 0)
	{
		if (must[i--] != file_name[len--])
			error(5);
	}
}
