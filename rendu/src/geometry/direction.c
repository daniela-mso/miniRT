/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marhuber <marhuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 10:18:20 by marhuber          #+#    #+#             */
/*   Updated: 2026/11/14 17:10:18 by marhuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../objects.h"

void	putendl_err(char *s);

int	direction_a2b(t_coord *point_a, t_coord *point_b, t_dir *result)
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

t_coord	move(t_coord *start, t_dir *direction, float coeff)
{
	t_coord	res;

	res.x = start->x + coeff * direction->x;
	res.y = start->y + coeff * direction->y;
	res.z = start->z + coeff * direction->z;
	return (res);
}

t_vector	difference(t_vector *a, t_vector *b)
{
	t_vector	res;

	res.x = a->x - b->x;
	res.y = a->y - b->y;
	res.z = a->z - b->z;
	return (res);
}

float	scalar_product(t_vector *a, t_vector *b)
{
	return (a->x * b->x + a->y * b->y + a->z * b->z);
}
