/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richardbrackswaide <richardbrackswaide@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 13:41:34 by richardbrac       #+#    #+#             */
/*   Updated: 2020/08/08 14:20:06 by richardbrac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				p_char(t_pfstruct *data)
{
    int				width;
    unsigned char	character;

	character = (unsigned char)va_arg(data->args, int);
	if (data->fs.wid && !data->fs.flag.minus)
	{
		width = data->fs.wid - 1;
		if (data->fs.flag.zero)
			data->pfreturn += write_chars(width, '0');
		else
			data->pfreturn += write_chars(width, ' ');
		data->pfreturn =+ write(1, &character, 1);
	}
	else if (data->fs.wid && data->fs.flag.minus)
	{
		data->pfreturn += write(1, &character, 1);
		width = data->pfreturn += write_chars(width, ' ');
	}
	else
		data->pfreturn += write(1, &character, 1);
}

void				p_percent(t_pfstruct *data)
{
	int				width;
	
	if (data->fs.wid && !data->fs.flag.minus)
	{
		width = data->fs.wid - 1;
		if (data->fs.flag.zero)
			data->pfreturn += write_chars(width, '0');
		else
			data->pfreturn += write(1, "%", 1);
	}
	else if (data->fs.wid && !data->fs.flag.minus)
	{
		data->pfreturn += write(1, "%", 1);
		width = data->fs.wid - 1;
		data->pfreturn += write_chars(width, ' ');
	}
	else
		data->pfreturn += write(1, "%", 1);
}