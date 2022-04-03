/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:56:49 by msousa            #+#    #+#             */
/*   Updated: 2022/04/03 21:48:03 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point	parse(std::string str)
{
    float   x, y;
    size_t  pos;

    pos = str.find(',');
    x = std::atof(str.substr(0, pos).c_str());
    y = std::atof(str.substr(pos + 1, str.length()).c_str());
    return Point(x, y);
}

int	main( int argc, char const *argv[] )
{
	// Example: 0,0 3,0 3,4 2,1

	if (argc != 5) {
		ERROR("4 <x,y> arguments required");
        return 1;
    }

    Point a = parse(argv[1]);
    Point b = parse(argv[2]);
    Point c = parse(argv[3]);
    Point point = parse(argv[4]);

	LOG("Point " << point << " is " << (bsp(a, b, c, point) ? "IN" : "OUT"));

	return 0;
}
