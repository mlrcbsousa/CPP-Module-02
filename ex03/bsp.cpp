/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 23:08:01 by msousa            #+#    #+#             */
/*   Updated: 2022/04/03 21:29:38 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*
https://math.stackexchange.com/questions/51326/determining-if-an-arbitrary-
point-lies-inside-a-triangle-defined-by-three-points

This is a fairly well known algorithm. It all comes down to using the cross
product. Define the vectors π΄π΅, π΅πΆ and πΆπ΄ and the vectors π΄π, π΅π and πΆπ.
Then π is inside the triangle formed by π΄,π΅ and πΆ if and only if all of the
cross products π΄π΅Γπ΄π, π΅πΆΓπ΅π and πΆπ΄ΓπΆπ point in the same direction relative to
the plane. That is, either all of them point out of the plane, or all of them
point into the plane.

https://blackpawn.com/texts/pointinpoly/
*/

bool	sameSide(Point const p1, Point const p2, Point const a, Point const b)
{
	Fixed cp1 = (b - a).cross(p1 - a);
	Fixed cp2 = (b - a).cross(p2 - a);

	// use (dot) product to find if vectors point in the same direction
	// given z axis was 0, dot product of [0, 0, cp1] . [0, 0, cp2] will be
	// c1 * c2
	return cp1 * cp2 >= 0;
}

bool	bsp( Point const a, Point const b, Point const c, Point const point )
{
	return 	sameSide(point, a, b, c)
		&&	sameSide(point, b, a, c)
		&&	sameSide(point, c, a, b);
}
