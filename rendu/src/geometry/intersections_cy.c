/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections_cy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marhuber <marhuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 15:35:22 by marhuber          #+#    #+#             */
/*   Updated: 2026/11/24 20:27:52 by marhuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../objects.h"

t_vec	difference(t_vec *minuend, t_vec *substrahend);
float	scalar_pr(t_vec *a, t_vec *b);
int		solve_quadratic_eq(float a, float b, float c, float res[2]);
t_vec	move(t_vec *start, t_dir *direction, float coeff);

int	int_inf_cyl(t_vec *start, t_dir *direction, t_cy *cyl, float res[2])
{
	t_vec	center2st;
	float	a;
	float	b;
	float	c;

	center2st = difference(start, &cyl->center);
	a = scalar_pr((t_vec *)direction, (t_vec *)&cyl->direction);
	c = scalar_pr(&center2st, (t_vec *)&cyl->direction);
	b = scalar_pr((t_vec *)direction, &center2st);
	b = 2 * (b - a * c);
	a = 1 - a;
	c = scalar_pr(&center2st, &center2st) - c * c;
	c = c - cyl->radius * cyl->radius;
	return (solve_quadratic_eq(a, b, c, res));
}

int	is_part(t_vec *start, t_dir *direction, t_cy *cyl, float coeff)
{
	t_vec	point;
	t_vec	center2p;

	point = move(start, direction, coeff);
	center2p = difference(&point, &cyl->center);
	if (scalar_pr(&center2p, (t_vec *)&cyl->direction) > cyl->half_height)
		return (0);
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
int	intsect_cy(t_vec *start, t_dir *direction, t_cy *cyl, float res[2])
{
	int		i;
	int		j;
	int		n;

	n = int_inf_cyl(start, direction, cyl, res);
	i = n;
	j = 0;
	while (i > 0 || j < n)
	{
		if (is_part(start, direction, cyl, res[j]))
			j++;
		else
		{
			i--;
			if (i > 0)
				res[0] = res [1];
		}
	}
	return (i);
}
