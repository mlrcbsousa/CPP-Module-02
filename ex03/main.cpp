/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:56:49 by msousa            #+#    #+#             */
/*   Updated: 2022/04/03 12:57:44 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main( void )
{
	Point a;
	Point b(3.0f, 0.0f);
	Point c = Point(3.0f, 4.0f);
	Point point(2.0f, 1.0f);

	// Test Point Constructors
	LOG(a);
	LOG(b);
	LOG(c);
	LOG(point);

	// Test BSP
	LOG( bsp(a, b, c, point) );

	return 0;
}
