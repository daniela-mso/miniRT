/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marhuber <marhuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 10:18:20 by marhuber          #+#    #+#             */
/*   Updated: 2026/11/21 22:35:30 by marhuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "../objects.h"

void	putendl_err(char *s);

float	scalar_product(t_vec *a, t_vec *b)
{
	return (a->x * b->x + a->y * b->y + a->z * b->z);
}

t_dir	*create_dir(t_vec *vector)
{
	t_dir	*res;
	float	squared;
	
	squared = scalar_product(vector, vector);
	if (squared == 0.f)
		return (putendl_err("error create_dir zero vector"), NULL);
	res = malloc(sizeof(*res));
	if (!res)
		return (perror("create_dir"), NULL);
	res->x = vector->x / sqrtf(squared);
	res->y = vector->y / sqrtf(squared);
	res->z = vector->z / sqrtf(squared);
	return (res);
}

t_vec	difference(t_vec *minuend, t_vec *substrahend)
{
	t_vec	res;

	res.x = minuend->x - substrahend->x;
	res.y = minuend->y - substrahend->y;
	res.z = minuend->z - substrahend->z;
	return (res);
}

t_dir	*direction_a2b(t_vec *point_a, t_vec *point_b)
{
	t_vec	vector;
	t_dir	*res;

	vector = difference(point_b, point_a);
	res = create_dir(&vector);
	if (!res)
		putendl_err("error direction_a2b two points equal");
	return (res);
}
