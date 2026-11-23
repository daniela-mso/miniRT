/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marhuber <marhuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 19:22:05 by marhuber          #+#    #+#             */
/*   Updated: 2026/11/23 22:15:45 by marhuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

// Basic types

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}		t_color;
// Question: int or char?

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
}			t_vec;

// A second struct with the same composition allows for a distinction between 
//  different types of data that can be enforced by the compiler.
// This type of structure should be used exclusively to save directions, e.g.
//  vectors with length one (that is x^2+y^2+z^2=1).
// This structure should thus be created using the appropriate fonction.
typedef struct s_direction
{
	float	x;
	float	y;
	float	z;
}			t_dir;

// Surfaces

typedef struct s_sphere
{
	float	radius;
	t_vec	center;
	t_color	color;
}			t_sp;

typedef struct s_plane
{
	t_vec	point;
	t_dir	normal;
	t_color	color;
}			t_pl;

typedef struct s_cylinder
{
	float	radius;
	float	half_height;
	t_vec	center;
	t_dir	direction;
	t_color	color;
}			t_cy;

typedef enum e_surface_type
{
	SP,
	PL,
	CY,
}	t_surface_type;

/**
* This is a generalized surface element
* @param data points at an instance of t_sp, t_pl or t_cy
* @param type indicates which one of those it is
*/
typedef struct s_surface_type
{
	void			*data;
	t_surface_type	type;
}	t_surface;

// List of surfaces

/**
* This is an element of a linked list
* @param content points at the content, eg. a string or another construct
* @param next points at the next element in the list or is NULL, if none exists
* the variable or element pointed at exists outside of this element
*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/**
* This is an element within a list of surfaces
* @param content points at an instance of t_surface
*/
typedef t_list			t_list_surface;

#endif