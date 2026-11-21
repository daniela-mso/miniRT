/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marhuber <marhuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 13:44:27 by marhuber          #+#    #+#             */
/*   Updated: 2026/11/21 22:39:38 by marhuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "main.h"

t_list	*ft_lstnew(void *content);
void	ft_lstclear(t_list **ptlst, void (*del)(void*));
void	del_surface(void *content);

void	usage_example(t_ctx *ctx)
{
	t_sp			*a_sphere;
	t_surface		*a_surface;
	t_list_surface	*list_element;
	t_vec			*point_a;
	t_vec			*point_b;
	t_dir			*first2second;

	// Creating the first sphere
	a_sphere = malloc(sizeof(*a_sphere));
	a_sphere->center.x = 4.5f;
	a_sphere->center.y = 4.5f;
	a_sphere->center.z = 2.5f;
	a_surface = malloc(sizeof(*a_surface));
	a_surface->data = a_sphere;
	a_surface->type = SP;
	// ...
	// Linking it as the first item of the list
	list_element = ft_lstnew(a_surface);
	ctx->surfaces = list_element;
	// Creating the second sphere 
	a_sphere = malloc(sizeof(*a_sphere));
	a_sphere->center.x = 4.5f;
	a_sphere->center.y = 5.5f;
	a_sphere->center.z = 3.5f;
	a_surface = malloc(sizeof(*a_surface));
	a_surface->data = a_sphere;
	a_surface->type = SP;
	// Linking it as the second item of the list
	list_element = ft_lstnew(a_surface);
	ctx->surfaces->next = list_element;
	// Computing the direction between from the first to the second sphere
	// fetch the coordinates of the center of the first sphere
	a_surface = ctx->surfaces->content;
	a_sphere = a_surface->data;
	point_a = &a_sphere->center;
	// fetch the coordinates of the center of the second sphere
	a_surface = ctx->surfaces->next->content;
	a_sphere = a_surface->data;
	point_b = &a_sphere->center;
	// malloc space for the result;
	first2second = direction_a2b(point_a, point_b);
	// print result
	printf("(%f, %f, %f)\n", first2second->x, first2second->y, first2second->z);
	// clean up
	ft_lstclear(&ctx->surfaces, &del_surface);
	free(first2second);
}

int	main(void)
{
	t_ctx	ctx;

	// (void) ctx;
	usage_example(&ctx);
}
