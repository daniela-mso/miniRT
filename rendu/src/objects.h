/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marhuber <marhuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 19:22:05 by marhuber          #+#    #+#             */
/*   Updated: 2026/10/02 20:21:10 by marhuber         ###   ########.fr       */
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

// Objects

typedef struct s_sphere
{
	t_coord	center;
	float	diameter;
	t_color	color;
}			t_sp;

typedef struct s_plane
{
	t_coord		center;
	t_vector	normal;
	t_color		color;
}				t_pl;

typedef struct s_cylinder
{
	t_coord		center;
	t_vector	direction;
	float		diameter;
	float		height;
	t_color		color;
}				t_cy;

// Question: Would it be possible to save the radius instead of the diameter?

// Lists of objects

/**
* This is an element of a linked list (
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
* This is an element within a list of spheres
* @param content points at an instance of t_sp
*/
typedef t_list			t_list_sp;

/**
* This is an element within a list of planes
* @param content points at an instance of t_pl
*/
typedef t_list			t_list_pl;

/**
* This is an element within a list of cylinders
* @param content points at an instance of t_cy
*/
typedef t_list			t_list_cy;

#endif