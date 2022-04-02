/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 23:09:49 by msousa            #+#    #+#             */
/*   Updated: 2022/04/02 21:11:35 by msousa           ###   ########.fr       */
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

	Fixed &		x( void ) const;
   	Fixed &		y( void ) const;
	void		set_x( Fixed const & x );
   	void		set_y( Fixed const & y );

private:

	Fixed const & _x, _y;

};

bool	bsp( Point const a, Point const b, Point const c, Point const point);

#endif /* __POINT_H__ */
