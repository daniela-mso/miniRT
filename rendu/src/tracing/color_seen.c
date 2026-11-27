/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_seen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marhuber <marhuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 16:15:37 by marhuber          #+#    #+#             */
/*   Updated: 2026/11/27 20:23:39 by marhuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"
#include "tracing.h"

int		intsect(t_vec *start, t_dir *direction, t_surface *surf, float *res);
t_vec	move(t_vec *start, t_dir *direction, float coeff);

int	first_point(t_ctx *ctx, t_dir *direction, t_point_seen *res)
{
	t_list_surface	*iterator;
	t_surface		*surface;
	float			coeff;
	float			candidate;

	coeff = -1.f;
	iterator = ctx->surfaces;
	while (iterator)
	{
		surface = iterator->content;
		if (intsect(&ctx->camera, direction, surface, &candidate) == 1)
		{
			if (coeff == -1.f || candidate < coeff)
			{
				coeff = candidate;
				res->surface = surface;
			}
		}
		iterator = iterator->next;
	}
	if (coeff > -1.f)
	{
		res->point = move(&ctx->camera, direction, coeff);
		return (1);
	}
	return (0);
}

int	color_at_point(t_ctx *ctx, t_point_seen *point, t_dir *dir, t_color *res)
{
	t_surface	*surf;

	(void) ctx;
	(void) dir;
	surf = point->surface;
	if (surf->type == SP)
		*res = ((t_sp *)(surf->data))->color;
	else if (surf->type == PL)
		*res = ((t_pl *)(surf->data))->color;
	else if (surf->type == CY)
		*res = ((t_cy *)(surf->data))->color;
	return (0);
}

int	color_seen(t_ctx *ctx, t_dir *direction, t_color *result)
{
	t_point_seen	point;

	if (first_point(ctx, direction, &point))
	{
		color_at_point(ctx, &point, direction, result);
	}
	else
	{
		(void) ctx;// just ambient lighting  
	}
	return (0);
}
