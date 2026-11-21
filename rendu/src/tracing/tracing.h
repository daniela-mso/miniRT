/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marhuber <marhuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 17:32:14 by marhuber          #+#    #+#             */
/*   Updated: 2026/11/01 11:19:31 by marhuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACING_H
# define TRACING_H

# include "../objects.h"

typedef struct s_point_seen
{
	t_coord			point;
	t_surface		*surface;
}	t_point_seen;

#endif