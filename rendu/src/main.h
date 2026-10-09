/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marhuber <marhuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 19:47:05 by marhuber          #+#    #+#             */
/*   Updated: 2026/10/09 10:42:15 by marhuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "objects.h"

/**
* This a structure make the information needed across the program available
* There will be only one instance of it created in the main function
* The most important functions will reference it
* ...
* @param spheres points at the start of a linked list of spheres
* @param planes points at the start of a linked list of planes
* @param cylinders points at the start of a linked list of cylinders
* If no sphere, plane or cylinder is present, the pointer is NULL
*/
typedef struct s_context
{
	// Information needed by MiniLibX to create the window...
	// Information about the camera, ambient light and the light spot
	t_list_sp	*spheres;
	t_list_pl	*planes;
	t_list_cy	*cylinders;
}					t_ctx;

// Common functions

/**
* This function computes the direction of segment between two points in space
* @param point_a points at the starting point
* @param point_b points at the destination point 
* @param result points at a memory space where the resulting direction is saved
* Returns 0 if successful, 1 if an error occurs
*/
int	direction_a2b(t_coord *point_a, t_coord *point_b, t_direction *result);

/**
* This function does the ray tracing
* Assumes that the ray starts at the camera, whose coordinates are in ctx
* @param ctx points at the context
* @param direction points at the direction of the ray to be traced 
* @param result points at a memory space where the resulting color is saved
* Returns 0 if successful, 1 if an error occurs
*/
int	tracing(t_ctx *ctx, t_direction *direction, t_color *result);

#endif // #ifndef MAIN_H