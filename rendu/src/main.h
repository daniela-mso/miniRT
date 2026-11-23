/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marhuber <marhuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 19:47:05 by marhuber          #+#    #+#             */
/*   Updated: 2026/11/23 21:15:21 by marhuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "objects.h"

/**
* This structure makes the information needed across the program available
* There will be only one instance of it created in the main function
* The most important functions will reference it
* ...
* @param surfaces points at the start of a linked list of spheres
* If no sphere, plane or cylinder is present, the pointer is NULL
*/
typedef struct s_context
{
	// Information needed by MiniLibX to create the window...
	// Information about the camera, ambient light and the light spot
	t_list_surface	*surfaces;
}					t_ctx;

// Common functions

/**
* This function computes the direction of segment between two points in space
* @param vector points at a vector, it must not be te zero vector
* @param res points at a memory space where the resulting direction is saved
* Returns 0 if successful, 1 if the vector is the zero vector
*/
int	create_dir(t_vec *vector, t_dir *res);

/**
* This function computes the direction of segment between two points in space
* @param point_a points at the starting point
* @param point_b points at the destination point 
* @param res points at a memory space where the resulting direction is saved
* Returns 0 if successful, 1 if both points are the same
*/
int	direction_a2b(t_vec *point_a, t_vec *, t_dir *res);

/**
* This function delivers the color seen by the camera in the direction given
* It assumes that the ray starts at the camera
* It assumes that the context is properly populated
* @param ctx points at the context
* @param direction points at the direction of the ray to be traced 
* @param result points at a memory space where the resulting color is saved
* Returns 0 if successful, 1 if an error occurs
*/
int		color_seen(t_ctx *ctx, t_dir *direction, t_color *result);

#endif // #ifndef MAIN_H