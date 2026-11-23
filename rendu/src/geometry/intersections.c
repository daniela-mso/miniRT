/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marhuber <marhuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 15:35:22 by marhuber          #+#    #+#             */
/*   Updated: 2026/11/23 22:24:36 by marhuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../objects.h"
#include <math.h>

t_vec	difference(t_vec *minuend, t_vec *substrahend);
float	scalar_product(t_vec *a, t_vec *b);


/** 
* computes the solutions of the quadratic equation
* @param a is the first coefficient
* @param b is the second
* @param c is the third
* @param res points at memory allocated to store the results of the equation
* returns 1 if a single solution is found, in this case,
*  a * res[0] ^ 2 + b * res[0] + c = 0
* returns 2 if a two solutions are found, in this case, also
*  a * res[1] ^ 2 + b * res[1] + c = 0
* returns 0 if there are no solutions
*/

int	solve_quadratic_eq(float a, float b, float c, float res[2])
{
	float	disc;

	disc = b * b - 4.0f * a * c;
	if (disc < 0.f)
		return (0);
	if (disc == 0.f)
	{
		*res = -b / 2.f / a;
		return (1);
	}
	*res = (sqrtf(disc) - b) / (2.f * a);
	res[1] = (-sqrtf(disc) - b) / (2.f * a);
	return (2);
}

/** 
* tries to compute the intersection point between a ray and a sphere
* @param start points at the starting point of the ray
* @param direcion points at the direction in which the ray starts
* @param sphere	points at the plane
* @param res points at memory allocated to store the resulting parameters
* returns 1 if a single intersection point is found, in this case,
*  start + res[0] * direction = a point that is part of the sphere
* returns 2 if a two intersection points are found, in this case, also
*  start + res[1] * direction = a point that is part of the sphere
* returns 0 if there are no intersections
*/
int	intsect_sp(t_vec *start, t_dir *direction, t_sp *sph, float res[2])
{
	t_vec	sta2cen;
	float		a;
	float		b;
	float		c;

	sta2cen = difference(start, &sph->center);
	a = 1.0f;
	b = 2.0f * scalar_product(&sta2cen, (t_vec *)direction);
	c = scalar_product(&sta2cen, &sta2cen) - sph->radius * sph->radius;
	return (solve_quadratic_eq(a, b, c, res));
}

/** 
* tries to compute the intersection point between a ray and a plane
* @param start points at the starting point of the ray
* @param direcion points at the direction in which the ray starts
* @param plane	points at the plane
* @param res points at memory allocated to store the resulting parameter
* returns 1 if a single intersection point is found, in this case,
*  start + res * direction = a point that is part of the plane
* returns 0 if there are no intersections
* returns 3 if the entire ray is part of the plane
*/
int	intsect_pl(t_vec *start, t_dir *direction, t_pl *plane, float res[1])
{
	t_vec	start2point;
	float		a;
	float		b;

	start2point = difference(start, &plane->point);
	a = scalar_product((t_vec *)direction, (t_vec *)&plane->normal);
	b = scalar_product(&start2point, (t_vec *)&plane->normal);
	if (a == 0.f)
	{
		if (b == 0.f)
			return (3);
		else
			return (0);
	}
	*res = -b / a;
	return (1);
}

/** 
* tries to compute the intersection point between a ray and a sphere
* @param start points at the starting point of the ray
* @param direcion points at the direction in which the ray starts
* @param cylinder points at the cylinder
* @param res points at memory allocated to store the resulting parameters
* returns 1 if a single intersection point is found, in this case,
*  start + res[0] * direction = a point that is part of the cylinder
* returns 2 if a two intersection points are found, in this case, also
*  start + res[1] * direction = a point that is part of the cylinder
* returns 0 if there are no intersections
* returns 3 if a segment of the ray is part of the clynder
*/
int	intsect_cy(t_vec *start, t_dir *direction, t_cy *cylinder, float res[2])
{
	(void) start;
	(void) direction;
	(void) cylinder;
	(void) res;
	return (0);
}

/** 
* tries to compute the first intersection point between a ray and a surface
* @param start points at the starting point of the ray
* @param direcion points at the direction in which the ray starts
* @param surf points at the surface
* @param res points at memory allocated to store the resulting parameter
* returns 1 if a good intersection point is found, in this case,
*  start + res * direction = a point that is part of the surface
*  res > 0
*  res is minimal
* returns 0 if there are no such intersections
* returns 3 if a segment of the ray is part of the surface
*/
int	intsect(t_vec *start, t_dir *direction, t_surface *surf, float *res)
{
	int		n;
	float	cand[2];

	if (surf->type == SP)
		n = intsect_sp(start, direction, surf->data, cand);
	else if (surf->type == PL)
		n = intsect_pl(start, direction, surf->data, cand);
	else if (surf->type == CY)
		n = intsect_cy(start, direction, surf->data, cand);
	if (n == 0 || n == 3)
		return (n);
	if ((cand[0] < 0.f) && (n == 1 || (n == 2 && cand[1] < 0.f)))
		return (0);
	*res = cand[0];
	if (n == 2 && (cand[0] < 0.f || (0 <= cand[1] && cand[1] < cand[0])))
		*res = cand[1];
	return (1);
}
