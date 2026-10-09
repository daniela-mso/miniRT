/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marhuber <marhuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 10:18:20 by marhuber          #+#    #+#             */
/*   Updated: 2026/10/09 21:34:05 by marhuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../objects.h"

void	putendl_err(char *s);

int	direction_a2b(t_coord *point_a, t_coord *point_b, t_direction *result)
{
	result->x = point_b->x - point_a->x;
	result->y = point_b->y - point_a->y;
	result->z = point_b->z - point_a->z;
	if (result->x == 0.f && result->y == 0.f && result->z == 0.f)
	{
		putendl_err("error direction_a2b");
		return (1);
	}
	return (0);
}
