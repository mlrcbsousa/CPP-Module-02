/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:56:49 by msousa            #+#    #+#             */
/*   Updated: 2022/04/02 19:39:10 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main( void )
{
	/* subject */

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;

	std::cout << b << std::endl;

	// std::cout << Fixed::max( a, b ) << std::endl;


	/* personal */

	Fixed c;
	Fixed const d( Fixed( 5.05f ) / Fixed( 2 ) );

	// std::cout << c << std::endl;
	// std::cout << ++c << std::endl;
	// std::cout << c << std::endl;
	// std::cout << c++ << std::endl;
	// std::cout << c << std::endl;

	std::cout << d << std::endl;

	// std::cout << Fixed::max( c, d ) << std::endl;

	return 0;
}
