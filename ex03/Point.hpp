/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 23:09:49 by msousa            #+#    #+#             */
/*   Updated: 2022/04/03 12:55:22 by msousa           ###   ########.fr       */
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
	Point( const float x, const float y );
	Point( Point const & src );
	~Point( void );
	Point & operator = ( Point const & rhs );

	Fixed const &	x( void ) const;
   	Fixed const &	y( void ) const;
	void			setX( Fixed const & x );
   	void			setY( Fixed const & y );

private:

	Fixed const 	_x, _y;

};

std::ostream &	operator << ( std::ostream & o, Point const & p);
bool	bsp( Point const a, Point const b, Point const c, Point const point);

#endif /* __POINT_H__ */
