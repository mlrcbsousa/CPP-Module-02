/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 23:08:01 by msousa            #+#    #+#             */
/*   Updated: 2022/04/03 13:09:48 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"


/* Constructors */

Point::Point( void ) : _x(Fixed()), _y(Fixed()) { /* no-op */ }

Point::Point( const float x, const float y ) : _x(Fixed(x)), _y(Fixed(y))
{ /* no-op */ }

Point::Point( Point const & src ) : _x(src.x()), _y(src.y()) { /* no-op */ }

Point::~Point( void ) { /* no-op */ }

Point & Point::operator = ( Point const & rhs )
{
	if (this != &rhs) {
		*this = Point(rhs);
	}
	return *this;
}

Fixed const &	Point::x( void ) const { return _x; }
Fixed const &	Point::y( void ) const { return _y; }

/* ostream override */
std::ostream &	operator << ( std::ostream & o, Point const & p)
{
	o << "(" << p.x() << ", " << p.y() << ")";
	return o;
}
