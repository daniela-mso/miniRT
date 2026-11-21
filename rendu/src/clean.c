/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marhuber <marhuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 10:51:41 by marhuber          #+#    #+#             */
/*   Updated: 2026/11/14 16:55:35 by marhuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "objects.h"

void	del_surface(void *content)
{
	t_surface	*surface;

	surface = content;
	free(surface->data);
	free(surface);
}
