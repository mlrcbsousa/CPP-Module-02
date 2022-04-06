/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 23:09:49 by msousa            #+#    #+#             */
/*   Updated: 2022/04/04 22:05:11 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __POINT_H__
# define __POINT_H__

# include "Fixed.hpp"

# define LOG(x) std::cout << x << std::endl
# define ERROR(x) std::cerr << x << std::endl

# define ABS(x) (((x) < 0) ? -(x) : (x))

// ************************************************************************** //
//                               Point Class                                  //
// ************************************************************************** //

class Point {

public:

	Point( void );
	Point( float const x, float const y );
	Point( Point const & src );
	~Point( void );
	Point & operator = ( Point const & rhs );

	float		x( void ) const;
   	float		y( void ) const;
	Fixed const	getX( void ) const;
   	Fixed const	getY( void ) const;

	/* arithmetic operators */
	Point 		operator - (Point const & rhs) const;

	/* vector arithmetic */
	Fixed		cross( Point const & p );

private:

	Fixed const 	_x, _y;

	Point( Fixed const x, Fixed const y );

};

std::ostream &	operator << ( std::ostream & o, Point const & p);
bool	bsp( Point const a, Point const b, Point const c, Point const point );

#endif /* __POINT_H__ */
