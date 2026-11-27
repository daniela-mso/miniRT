/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marhuber <marhuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 13:44:27 by marhuber          #+#    #+#             */
/*   Updated: 2026/11/27 20:26:01 by marhuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "objects.h"
#include <stdio.h>
#include <stdlib.h>


t_list	*ft_lstnew(void *content);
int		color_seen(t_ctx *ctx, t_dir *direction, t_color *result);
void	ft_lstclear(t_list **ptlst, void (*del)(void*));
void	del_surface(void *content);

void	usage_example(t_ctx *ctx)
{
	t_sp			*a_sphere;
	t_pl			*a_plane;
	t_surface		*a_surface;
	t_list_surface	*list_element;
	t_dir			dir;
	t_color			color;

	// Creating the first sphere
	a_sphere = malloc(sizeof(*a_sphere));
	a_sphere->center.x = 2.f;
	a_sphere->center.y = 0.f;
	a_sphere->center.z = 0.f;
	a_sphere->radius = 1;
	a_sphere->color.b = 256;
	a_surface = malloc(sizeof(*a_surface));
	a_surface->data = a_sphere;
	a_surface->type = SP;
	// Linking it as the first item of the list
	list_element = ft_lstnew(a_surface);
	ctx->surfaces = list_element;
	// Creating the second sphere 
	a_sphere = malloc(sizeof(*a_sphere));
	a_sphere->center.x = 4.f;
	a_sphere->center.y = 0.f;
	a_sphere->center.z = 0.f;
	a_sphere->radius = 2;
	a_sphere->color.b = 127;
	a_surface = malloc(sizeof(*a_surface));
	a_surface->data = a_sphere;
	a_surface->type = SP;
	// Linking it as the second item of the list
	list_element = ft_lstnew(a_surface);
	ctx->surfaces->next = list_element;
	// create a plane
	a_plane = malloc(sizeof(*a_plane));
	a_plane->point.x = 3.5f;
	a_plane->point.y = 7.f;
	a_plane->point.z = -9.f;
	a_plane->normal.x = 1.f;
	a_plane->normal.y = 0.f;
	a_plane->normal.z = 0.f;
	a_plane->color.b = 63;
	a_surface = malloc(sizeof(*a_surface));
	a_surface->data = a_plane;
	a_surface->type = PL;
	// Linking it as the third item of the list
	list_element = ft_lstnew(a_surface);
	ctx->surfaces->next->next = list_element;
	// Place camera
	ctx->camera.x = 0.f;
	ctx->camera.y = 10.f;
	ctx->camera.z = 0.f;
	dir.x = -1.f;
	dir.y = 0.f;
	dir.z = 0.f;
	color_seen(ctx, &dir, &color);
	printf("%d\n", color.b);
	// clean up
	ft_lstclear(&ctx->surfaces, &del_surface);
}

int	main(void)
{
	t_ctx	ctx;

	// (void) ctx;
	usage_example(&ctx);
}
