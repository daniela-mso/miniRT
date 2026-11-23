/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marhuber <marhuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 10:18:20 by marhuber          #+#    #+#             */
/*   Updated: 2026/11/23 22:26:15 by marhuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../objects.h"

void	putendl_err(char *s);

float	scalar_product(t_vec *a, t_vec *b)
{
	return (a->x * b->x + a->y * b->y + a->z * b->z);
}

int	create_dir(t_vec *vector, t_dir *res)
{
	float	squared;

	squared = scalar_product(vector, vector);
	if (squared == 0.f)
		return (putendl_err("error create_dir zero vector"), 1);
	res->x = vector->x / sqrtf(squared);
	res->y = vector->y / sqrtf(squared);
	res->z = vector->z / sqrtf(squared);
	return (0);
}

t_vec	difference(t_vec *minuend, t_vec *substrahend)
{
	t_vec	res;

	res.x = minuend->x - substrahend->x;
	res.y = minuend->y - substrahend->y;
	res.z = minuend->z - substrahend->z;
	return (res);
}

int	direction_a2b(t_vec *point_a, t_vec *point_b, t_dir *res)
{
	t_vec	vector;

	vector = difference(point_b, point_a);
	if (create_dir(&vector, res))
		return (putendl_err("error direction_a2b two points equal"), 1);
	return (0);
}

t_vec	move(t_vec *start, t_dir *direction, float coeff)
{
	t_vec	res;

	res.x = start->x + coeff * direction->x;
	res.y = start->y + coeff * direction->y;
	res.z = start->z + coeff * direction->z;
	return (res);
}
