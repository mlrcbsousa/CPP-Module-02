/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 23:08:01 by msousa            #+#    #+#             */
/*   Updated: 2022/04/03 23:24:50 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/* Constructors */
Point::Point( void ) : _x(Fixed()), _y(Fixed()) { /* no-op */ }
Point::Point( Point const & src ) : _x(src.x()), _y(src.y()) { /* no-op */ }
Point::Point( float const x, float const y ) : _x(Fixed(x)), _y(Fixed(y)) { /**/ }
Point::Point( Fixed const x, Fixed const y ) : _x(x), _y(y) { /* no-op */ }

/* Destructor */
Point::~Point( void ) { /* no-op */ }

/* Assignment operator */
Point & Point::operator = ( Point const & rhs )
{
	if (this != &rhs) {
		*this = Point(rhs);
	}
	return *this;
}

/* Accessors */
float	Point::x( void ) const { return _x.toFloat(); }
float	Point::y( void ) const { return _y.toFloat(); }
Fixed const	Point::getX( void ) const { return _x; }
Fixed const	Point::getY( void ) const { return _y; }

/* Instance methods */
Point 	Point::operator - (Point const & rhs) const
{
	// Use private Fixed type args constructor
	return Point(getX() - rhs.getX(), getY() - rhs.getY());
}

Fixed	Point::cross( Point const & p )
{
	// (𝑥1, 𝑦1, 0) × (𝑥2, 𝑦2, 0) = (0, 0, 𝑥1𝑦2 − 𝑥2𝑦1)
	// third element of cross product if z1 and z2 = 0
	return (getX() * p.getY() - p.getX() * getY());
}


/* ostream override */
std::ostream &	operator << ( std::ostream & o, Point const & p)
{
	o << "(" << p.x() << ", " << p.y() << ")";
	return o;
}
