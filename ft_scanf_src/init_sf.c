/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 19:19:34 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/07 16:46:17 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	set_handler(t_sfhandler *handler, char *v, int (*f)(t_sf *sf))
{
	handler->c = *v;
	handler->f = f;
}

static void	init_sf_specifiers(t_sf *sf)
{
	t_sfhandler *handlers;

	handlers = sf->handlers;
	set_handler(handlers, "d", &sf_handler_di);
	set_handler(handlers + 1, "i", &sf_handler_di);
	set_handler(handlers + 2, "s", &sf_handler_s);
	set_handler(handlers + 3, "c", &sf_handler_c);
}

int			init_sf(t_sf *sf, int fd)
{
	ft_bzero(sf, sizeof(t_sf));
	sf->fd = fd;
	init_sf_specifiers(sf);
	return (1);
}
