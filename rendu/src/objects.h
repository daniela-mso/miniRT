/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marhuber <marhuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 19:22:05 by marhuber          #+#    #+#             */
/*   Updated: 2026/11/01 10:22:11 by marhuber         ###   ########.fr       */
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

struct s_vector
{
	float	x;
	float	y;
	float	z;
};

// Question: Using Two different types to reflect meaning?
typedef struct s_vector	t_coord;
typedef struct s_vector	t_direction;
// Or one?
typedef struct s_vector	t_vector;

// Difference: A coordinate can be (0, 0, 0), which is the vector zero.
// A vector zero as a coordinate represents the "center" or origin of the 
// coordinates system.
// A direction cannot be the vector zero.

// Surfaces

typedef struct s_sphere
{
	t_coord	center;
	float	radius;
	t_color	color;
}			t_sp;

typedef struct s_plane
{
	t_coord		point;
	t_vector	normal;
	t_color		color;
}				t_pl;

typedef struct s_cylinder
{
	t_coord		center;
	t_vector	direction;
	float		radius;
	float		half_height;
	t_color		color;
}				t_cy;

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