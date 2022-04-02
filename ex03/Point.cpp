/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 23:08:01 by msousa            #+#    #+#             */
/*   Updated: 2022/04/02 21:16:33 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"


/* Constructors */

Point::Point( void ) : _x(Fixed()), _y(Fixed()) { /* no-op */ }

Point::Point( const float x, const float y ) :
	_x(Fixed(x)), _y(Fixed(y))
	{ /* no-op */ }

Point::Point( Point const & src )
{}

Point::~Point( void )
{}

Point & Point::operator = ( Point const & rhs )
{}

Fixed &		Point::x( void ) const
{}

Fixed &		Point::y( void ) const
{}

void		Point::set_x( Fixed const & x )
{}

void		Point::set_y( Fixed const & y )
{}
