/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marhuber <marhuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 13:44:27 by marhuber          #+#    #+#             */
/*   Updated: 2026/10/09 21:38:00 by marhuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "objects.h"
#include <stdio.h>
#include <stdlib.h>

t_list	*ft_lstnew(void *content);
void	ft_lstclear(t_list **ptlst, void (*del)(void*));

void	usage_example(t_ctx *ctx)
{
	t_sp		*a_sphere;
	t_list_sp	*list_element;
	t_coord		*point_a;
	t_coord		*point_b;
	t_direction	*first2second;

	// Creating the first sphere
	a_sphere = malloc(sizeof(*a_sphere));
	a_sphere->center.x = 4.5f;
	a_sphere->center.y = 4.5f;
	a_sphere->center.z = 2.5f;
	// ...
	// Linking it as the first item of the list
	list_element = ft_lstnew(a_sphere);
	ctx->spheres = list_element;
	// Creating the second sphere 
	a_sphere = malloc(sizeof(*a_sphere));
	a_sphere->center.x = 4.5f;
	a_sphere->center.y = 4.5f;
	a_sphere->center.z = -2.5f;
	// Linking it as the second item of the list
	list_element = ft_lstnew(a_sphere);
	ctx->spheres->next = list_element;
	// Computing the direction between from the first to the second sphere
	// fetch the coordinates of the center of the first sphere
	a_sphere = ctx->spheres->content;
	point_a = &a_sphere->center;
	// fetch the coordinates of the center of the second sphere
	a_sphere = ctx->spheres->next->content;
	point_b = &a_sphere->center;
	// malloc space for the result;
	first2second = malloc(sizeof(*first2second));
	direction_a2b(point_a, point_b, first2second);
	// print result
	printf("(%f, %f, %f)\n", first2second->x, first2second->y, first2second->z);
	// clean up
	ft_lstclear(&ctx->spheres, free);
	free(first2second);
}

int	main(void)
{
	t_ctx	ctx;

	// (void) ctx;
	usage_example(&ctx);
}
